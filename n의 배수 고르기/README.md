### n의 배수 고르기

### Quiz Description
> 정수 n과 정수 배열 numlist가 매개변수로 주어질 때, numlist에서 n의 배수가 아닌 수들을 제거한 배열을 return하도록 solution 함수를 완성해주세요.

### Solution
1. 문제는 인자로 받은 int[]을 순회하면서 n의 배수가 있을 경우 n의 배수로만 이루어진 int[]을 반환하는 것이다. 
2. numlist[i] % n == 0과 같은 방식으로 numlist[]의 요소를 n으로 나누어 나머지가 없을 경우 n의 배수이기 때문에 함수 point_n을 만들어 반환할 int[]의 길이를 구한다. 
3. point_n을 통해 구한 길이만큼 동적할당한 후 같은 방식으로 int[]를 순회하면서 n의 배수를 새로 만든 배열에 넣고 이를 반환한다.