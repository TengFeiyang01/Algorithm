#include <bits/stdc++.h>
#include "../headers/BeiJingTime.h"
#include "../headers/TokyoTime.h"
#include "../headers/CanadaTime.h"
#include "../headers/LondonTime.h"


int main() {
    TokyoTime tt;
    LondonTime lt;
    CanadaTime ct;
    BeiJingTime bt;

    bt.registerObserver(&tt);
    bt.registerObserver(&lt);
    bt.registerObserver(&ct);

    bt.setTime(100, 150, 200);


    std::cout << "=======================\n";
    bt.removeObserver(&ct);
    //now the CanadaTime has been removed so CanadaTime is still keep the last change
    bt.setTime(100, 150, 200);

    std::cout << "=======================\n";
    bt.registerObserver(&ct);
    bt.setTime(100, 150, 200);

    return 0;
}
