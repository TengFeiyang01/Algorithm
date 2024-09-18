#include <cstdint>
#include <vector>

namespace std{

template <uint32_t mod>
class mod_int{
    private:
        static constexpr uint32_t get_r(){
            uint32_t ret = mod;
            for(int i = 0; i < 4; i++) ret *= 2 - mod * ret;
            return ret;
        }
        static constexpr uint32_t r = get_r();
        static constexpr uint32_t n2 = -uint64_t(mod) % mod;
        static_assert(r * mod == 1, "invalid, r * mod != 1");
        static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
        static_assert(mod & 1, "invalid, mod % 2 == 0");
        uint32_t data;
    public:
        constexpr mod_int() : data(0){}
        template <class int_t>
        constexpr mod_int(const int_t x): data(reduce(uint64_t(x % mod + mod) * n2)){};
        static constexpr uint32_t reduce(const uint64_t x){
            return (x + uint64_t(uint32_t(x) * (-r)) * mod) >> 32;
        }
        constexpr mod_int& operator += (const mod_int &rhs){
            if(int32_t(data += rhs.data - 2 * mod) < 0){data += 2 * mod;} return (*this);
        }
        constexpr mod_int& operator -= (const mod_int &rhs){
            if(int32_t(data -= rhs.data) < 0){data += 2 * mod;} return (*this);
        }
        constexpr mod_int& operator *= (const mod_int &rhs){
            return data = reduce((uint64_t)data * rhs.data), (*this);
        }
        constexpr mod_int& operator /= (const mod_int &rhs){
            return (*this) *= rhs.inv();
        }
        constexpr mod_int operator + (const mod_int &rhs) const {return mod_int(*this) += rhs;}
        constexpr mod_int operator - (const mod_int &rhs) const {return mod_int(*this) -= rhs;}
        constexpr mod_int operator * (const mod_int &rhs) const {return mod_int(*this) *= rhs;}
        constexpr mod_int operator / (const mod_int &rhs) const {return mod_int(*this) /= rhs;}
        constexpr mod_int operator - () const {return mod_int() - mod_int(*this);}
        template <class int_t>
        constexpr mod_int pow(int_t rhs) const {
            mod_int res(1), w(*this); for(; rhs; rhs >>= 1, w *= w) if(rhs & 1) res *= w;
            return res;
        }
        constexpr mod_int inv() const {return pow(mod - 2);}
        constexpr uint32_t value() const {
            uint32_t res = reduce(data);
            return res >= mod? res - mod: res;
        }
};

template <uint32_t mod, uint32_t g>
class poly: private vector<mod_int<mod>>{
    private:
        typedef mod_int<mod> mint;
        static inline vector<mint> w, iw;
        static size_t ceil2pow(size_t n){return 1 << (__lg(n - 1) + 1);};
        static void DIF(mint *A, size_t n){
            if(n > w.size()){
                mint w0 = mint(g).pow((mod - 1) / n); w.resize(n), w[n >> 1] = 1;
                for(size_t i = 1; i < (n >> 1); i++) w[(n >> 1) + i] = w[(n >> 1) + i - 1] * w0;
                for(size_t i = (n >> 1) - 1; i; i--) w[i] = w[i << 1];
            }
            for(size_t k = n >> 1; k; k >>= 1)
            for(size_t i = 0; i < n; i += k << 1)
            for(size_t j = 0; j < k; j++){
                mint x = A[i + j], y = A[i + j + k];
                A[i + j] = x + y, A[i + j + k] = w[j + k] * (x - y);
            }
        }
        static void DIT(mint *A, size_t n){
            if(n > iw.size()){
                mint iw0 = mint(g).pow(mod - 2).pow((mod - 1) / n); iw.resize(n), iw[n >> 1] = 1;
                for(size_t i = 1; i < (n >> 1); i++) iw[(n >> 1) + i] = iw[(n >> 1) + i - 1] * iw0;
                for(size_t i = (n >> 1) - 1; i; i--) iw[i] = iw[i << 1];
            }
            for(size_t k = 1; k < n; k <<= 1)
            for(size_t i = 0; i < n; i += k << 1)
            for(size_t j = 0; j < k; j++){
                mint x = A[i + j], y = iw[j + k] * A[i + j + k];
                A[i + j] = x + y, A[i + j + k] = x - y;
            }
            mint n_inv = mint(n).inv();
            for(size_t i = 0; i < n; i++) A[i] *= n_inv;
        }
        static void poly_neg(mint *idx0, size_t n){
            for(size_t i = 0; i < n; i++) idx0[i] = -idx0[i];
        }
        static void poly_add(mint *idx0, mint *idx1, size_t n){
            for(size_t i = 0; i < n; i++) idx0[i] += idx1[i];
        }
        static void poly_sub(mint *idx0, mint *idx1, size_t n){
            for(size_t i = 0; i < n; i++) idx0[i] -= idx1[i];
        }
        static void poly_mul(mint *idx0, mint num1, size_t n){
            for(size_t i = 0; i < n; i++) idx0[i] *= num1;
        }
        static void poly_mul(mint *idx0, mint *idx1, size_t n){
            mint mem0[n];
            copy(idx1, idx1 + n, mem0);
            DIF(idx0, n), DIF(mem0, n);
            for(size_t i = 0; i < n; i++) idx0[i] *= mem0[i];
            DIT(idx0, n);
        }
        static void poly_inv(mint *idx0, mint *idx1, size_t n){
            fill(idx0, idx0 + n, 0);
            mint mem0[n]; idx0[0] = idx1[0].inv();
            for(size_t k = 1; k < n; k <<= 1){
                copy(idx0, idx0 + k, mem0);
                poly_mul(mem0, idx1, k << 1);
                fill(mem0, mem0 + k, 0);
                poly_mul(mem0, idx0, k << 1);
                poly_mul(idx0 + k, 2, k);
                poly_sub(idx0 + k, mem0 + k, k);
            }
        }
        static void poly_sqr(mint *idx0, mint *idx1, size_t n){
            copy(idx1, idx1 + n, idx0), DIF(idx0, n);
            for(size_t i = 0; i < n; i++) idx0[i] *= idx0[i];
            DIT(idx0, n);
        }
        static void poly_sqrt(mint *idx0, mint *idx1, size_t n){
            fill(idx0, idx0 + n, 0);
            mint mem0[n << 1], mem1[n << 1]; idx0[0] = 1;
            for(size_t k = 1; k < n; k <<= 1){
                poly_inv(mem0, idx0, k << 1);
                poly_mul(mem0, mint(2).inv(), k << 1);
                copy(idx1, idx1 + (k << 1), mem1);
                poly_mul(mem0, mem1, k << 2);
                poly_add(idx0 + k, mem0 + k, k);
            }
        }
        static void poly_exp(mint *idx0, mint *idx1, size_t n){
            fill(idx0, idx0 + n, 0);
            mint mem0[n << 1]; idx0[0] = 1;
            for(size_t k = 1; k < n; k <<= 1){
                poly_log(mem0, idx0, k << 1);
                poly_sub(mem0, idx1, k << 1);
                poly_mul(mem0, idx0, k << 1);
                poly_sub(idx0 + k, mem0 + k, k);
            }
        }
        static void poly_log(mint *idx0, mint *idx1, size_t n){
            mint mem0[n << 1];
            poly_deriv(idx0, idx1, n);
            poly_inv(mem0, idx1, n);
            poly_mul(idx0, mem0, n << 1);
            poly_integ(idx0, idx0, n);
        }
        static void poly_sin(mint *idx0, mint *idx1, size_t n){
            mint mem0[n << 1], mem1[n << 1], i = mint(g).pow((mod - 1) / 4);
            copy(idx1, idx1 + n, mem1), poly_mul(mem1,  i, n), poly_exp(idx0, mem1, n);
            copy(idx1, idx1 + n, mem1), poly_mul(mem1, -i, n), poly_exp(mem0, mem1, n);
            poly_sub(idx0, mem0, n), poly_mul(idx0, (i * 2).inv(), n);
        }
        static void poly_cos(mint *idx0, mint *idx1, size_t n){
            mint mem0[n << 1], mem1[n << 1], i = mint(g).pow((mod - 1) / 4);
            copy(idx1, idx1 + n, mem1), poly_mul(mem1,  i, n), poly_exp(idx0, mem1, n);
            copy(idx1, idx1 + n, mem1), poly_mul(mem1, -i, n), poly_exp(mem0, mem1, n);
            poly_add(idx0, mem0, n), poly_mul(idx0, mint(2).inv(), n);
        }
        static void poly_asin(mint *idx0, mint *idx1, size_t n){
            mint mem0[n << 1]; copy(idx1, idx1 + n, mem0);
            poly_sqr(mem0, mem0, n << 1), poly_neg(mem0, n), mem0[0] += 1;
            poly_sqrt(idx0, mem0, n), poly_inv(mem0, idx0, n), poly_deriv(idx0, idx1, n);
            fill(mem0 + n, mem0 + (n << 1), 0), fill(idx0 + n, idx0 + (n << 1), 0);
            poly_mul(mem0, idx0, n << 1), poly_integ(idx0, mem0, n);
        }
        static void poly_atan(mint *idx0, mint *idx1, size_t n){
            mint mem0[n << 1]; copy(idx1, idx1 + n, mem0);
            poly_sqr(idx0, mem0, n << 1), idx0[0] += 1;
            poly_inv(mem0, idx0, n), poly_deriv(idx0, idx1, n);
            fill(mem0 + n, mem0 + (n << 1), 0), fill(idx0 + n, idx0 + (n << 1), 0);
            poly_mul(mem0, idx0, n << 1), poly_integ(idx0, mem0, n);
        }
        static void poly_deriv(mint *idx0, mint *idx1, size_t n){
            for(size_t i = 1; i < n; i++) idx0[i - 1] = idx1[i] * i;
            idx0[n - 1] = 0;
        }
        static void poly_integ(mint *idx0, mint *idx1, size_t n){
            mint mem0[n]; mem0[1] = 1;
            for(size_t i = 2; i < n; i++) mem0[i] = -mem0[mod % i] * (mod / i);
            for(size_t i = n; i > 1; i--) idx0[i - 1] = idx1[i - 2] * mem0[i - 1];
            idx0[0] = 0;
        }
    public:
        poly(size_t len = 0): vector<mint>(len){}
        auto begin() const {return vector<mint>::begin();}
        auto end  () const {return vector<mint>::end  ();}
        mint& operator [] (const size_t &idx){
            return vector<mint>::operator[](idx);
        }
        const mint operator [] (const size_t &idx) const {
            return vector<mint>::operator[](idx);
        }
        size_t size() const {return vector<mint>::size();}
        poly& operator += (const poly &rhs){
            this->resize(max(size(), rhs.size()));
            for(size_t i = 0; i < rhs.size(); i++) this->data()[i] += rhs.data()[i];
            return (*this);
        }
        poly& operator -= (const poly &rhs){
            this->resize(max(size(), rhs.size()));
            for(size_t i = 0; i < rhs.size(); i++) this->data()[i] -= rhs.data()[i];
            return (*this);
        }
        poly& operator *= (const poly &rhs){
            size_t n = size() + rhs.size() - 1, lim = ceil2pow(n) << 1;
            this->resize(lim); mint tmp[lim]; copy(rhs.data(), rhs.data() + rhs.size(), tmp);
            return poly_mul(this->data(), tmp, lim), this->resize(n), (*this);
        }
        poly operator += (const mint &rhs){return (*this)[0] += rhs, (*this);}
        poly operator -= (const mint &rhs){return (*this)[0] -= rhs, (*this);}
        poly operator *= (const mint &rhs){return poly_mul(this->data(), rhs, size()), (*this);}
        poly operator /= (const mint &rhs){return (*this) *= rhs.inv();}
        poly operator - () const {return poly() -= (*this);}
        template <class type> poly operator + (const type &rhs) const {return poly(*this) += rhs;}
        template <class type> poly operator - (const type &rhs) const {return poly(*this) -= rhs;}
        template <class type> poly operator * (const type &rhs) const {return poly(*this) *= rhs;}
        template <class type> poly operator / (const type &rhs) const {return poly(*this) /= rhs;}
        template <class type> poly operator % (const type &rhs) const {return poly(*this) %= rhs;}
#define _POLY_INIT_FUNC(func_name, sfl)\
        poly func_name() const {\
            size_t n = size(), lim = ceil2pow(n); mint tmp[lim << sfl]; poly res(lim << sfl);\
            copy(this->data(), this->data() + size(), tmp);\
            return poly_ ## func_name(res.data(), tmp, lim), res.resize(n), res;\
        }
        _POLY_INIT_FUNC(inv , 0) _POLY_INIT_FUNC(sqrt, 1)
        _POLY_INIT_FUNC(exp , 1) _POLY_INIT_FUNC(log , 1)
        _POLY_INIT_FUNC(sin , 1) _POLY_INIT_FUNC(cos , 1)
        _POLY_INIT_FUNC(asin, 1) _POLY_INIT_FUNC(atan, 1)
#undef _POLY_INIT_FUNC
        template <class int_t>
        poly pow(int_t rhs) const {
            return (log() * mint(rhs)).exp();
        }
        poly deriv() const {
            poly res(size() - 1);
            return poly_deriv(res.data(), this->data(), size()), res;
        }
        poly integ() const {
            poly res(size() + 1);
            return poly_integ(res.data(), this->data(), size()), res;
        }
};

} // namespace std

#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 998244353, G = 3;
// template <auto mod>
// auto read(){
//     decltype(mod) res = 0; char chr = cin.get();
//     for(; !isdigit(chr); chr = cin.get());
//     for(;  isdigit(chr); chr = cin.get()) res = (res * 10 + (chr - '0')) % mod;
//     return res;
// }
int main(){
    int n, m;
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    poly<MOD, G> A(m + 1);
    for(int i = 0; i <= 9; i++){A[i] = 1;}
    auto F = A.pow(n - 1);
    A[0] = 0;
    F *= A;
    cout << F[m].value() << "\n";
}