### 숫자 찾기

### Quiz Description
> 정수 num과 k가 매개변수로 주어질 때, num을 이루는 숫자 중에 k가 있으면 num의 그 숫자가 있는 자리 수를 return하고 없으면 -1을 return 하도록 solution 함수를 완성해보세요.

### Solution
1. 먼저 인자로 받은 num을 itoa()에 넣어서 동일한 값을 가지는 문자열로 반환한다. 
2. itoa()로부터 반환받은 문자열 str을 순회하면서 인자로 받은 k와 비교한다. 
3. 이때, 인자로 받은 k는 int이고, 문자열은 char이기 때문에 문자를 int로 타입 캐스팅해준 후 -48을 연산하여 숫자로 바꾼 뒤 계산한다. -48을 연산하는 이유는 아스키코드를 참고한다. 
4. 최종적으로 str을 순회할 때 사용한 index i를 반환하고, k를 발견하지 못할 경우 -1을 반환한다. 