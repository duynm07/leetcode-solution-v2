**`f[i][j]`**: The imbalance number of the subarray `nums[i]..nums[j]`.

- If `nums[j]` has already appeared in the subarray `nums[i]..nums[j-1]`, adding `nums[j]` does not make any difference. Hence, `f[i][j] = f[i][j-1]`.
- If not:

    - If both `nums[j] - 1` and `nums[j] + 1` have already appeared in the subarray `nums[i]..nums[j-1]`, adding `nums[j]` will result in a lower imbalance number. Therefore, `f[i][j] = f[i][j-1] - 1`.
    - If neither `nums[j] - 1` nor `nums[j] + 1` exists in the subarray, adding `nums[j]` will result in a higher imbalance number. Hence, `f[i][j] = f[i][j-1] + 1`.
    - In all other cases, the imbalance number remains unchanged, i.e., `f[i][j] = f[i][j-1]`.

The answer is the sum of all `f[i][j]`.
