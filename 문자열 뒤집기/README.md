### 문자열 뒤집기 \

### Quiz Description
> 문자열 my_string이 매개변수로 주어집니다. my_string을 거꾸로 뒤집은 문자열을 return하도록 solution 함수를 완성해주세요.

### Solution
1. 인자로 받은 문자열이 상수이기 때문에 duplicate_str()을 만들어 문자열을 복사한다. 
2. 인자로 받은 문자열 길이의 절반만큼 for문을 돌리면서 양 끝에 있는 요소를 바꿔준다. 