def batchnorm_forward(x, gamma, beta, bn_param):
 
    mode = bn_param['mode']
    eps = 1e-8
    momentum = bn_param.get('momentum', 0.9)

    N, D = x.shape
    running_mean = bn_param.get('running_mean', np.zeros(D, dtype=x.dtype))
    running_var = bn_param.get('running_var', np.zeros(D, dtype=x.dtype))

    out, cache = None, None

    if mode == 'train':
        sample_mean = np.mean(x, axis=0) #np.mean([[1,2],[3,4]])->[2,3]
        sample_var = np.var(x, axis=0)
        out_ = (x - sample_mean) / np.sqrt(sample_var + eps)
       
        running_mean = momentum * running_mean + (1 - momentum) * sample_mean
        running_var = momentum * running_var + (1 - momentum) * sample_var

        out = gamma * out_ + beta
        cache = (out_, x, sample_var, sample_mean, eps, gamma, beta)
    elif mode == 'test':
        # scale = gamma / np.sqrt(running_var + eps)
        # out = x * scale + (beta - running_mean * scale)
        x_hat = (x - running_mean) / (np.sqrt(running_var + eps))
        out = gamma * x_hat + beta
    else:
        raise ValueError('Invalid forward batchnorm mode "%s"' % mode)

    # Store the updated running means back into bn_param
    bn_param['running_mean'] = running_mean
    bn_param['running_var'] = running_var

    return out, cache
print(batchnorm_forward)