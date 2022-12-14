# ABS => MIN MAX
abs(a - b) = max(a, b) - min(a, b) <br />
max(a, b) = a + b - min(a, b) <br />
=> abs(a - b) = a + b - 2 * min(a , b) <br />
=> abs(a - b) = f1* a - f1 * b [f1 = sign] <br/>
### Transformation from i, j => min, max H, K
delta = | A[i] - A[j] | + | A[i + 1] - A[j + 1] | - | A[i] - A[i + 1] | - | A[j] - A[j + 1] |  <br />
L[i] = min(A[i], A[i + 1])  <br />
H[i] = max(A[i], A[i + 1])  <br /> 
L[j] = min(A[j], A[j + 1])  <br />
H[j] = max(A[j], A[j + 1])  <br />
