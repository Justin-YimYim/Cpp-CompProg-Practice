# ABS => MIN MAX
abs(a - b) = max(a, b) - min(a, b) <br />
max(a, b) = a + b - min(a, b) <br />
=> abs(a - b) = a + b - 2 * min(a , b) <br />
### Transformation from i, j => min, max H, K
delta = | A[i] - A[j] | + | A[i + 1] - A[j + 1] | - | A[i] - A[i + 1] | - | A[j] - A[j + 1] |
L[i] = min(A[i], A[i + 1])
H[i] = max(A[i], A[i + 1])
L[j] = min(A[j], A[j + 1])
H[j] = max(A[j], A[j + 1])
