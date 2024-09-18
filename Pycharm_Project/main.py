import numpy as np


def distance_to_last_true(arr: np.ndarray) -> np.ndarray:
    result = np.full_like(arr, -1, dtype=np.int64)

    true_indices = np.flatnonzero(arr)

    if true_indices.size == 0:
        return result

    pos = np.full(arr.shape, -1, dtype=np.int64)
    pos[true_indices] = true_indices
    pos = np.maximum.accumulate(pos)

    st = pos >= 0
    result[st] = np.arange(len(arr))[st] - pos[st]

    return result

