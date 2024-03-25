## 어려웠던점

### 실행 스크립트인 .gradle 에서 spring bean 값 전달까지 과정

---
[최소한의 셋팅으로 값을 전달하기 까지 과정] 

나는 기본으로 만들어지는 .gradle 에서 필요한 값을 spring bean 에 전달하기 위해서
.gradle 과 spring 의 생명주기를 분석하고 값을 전달하기 위해 필요한 것을
chatgpt 의 도움을 받아보려했으나 최신버전은 정보가 없어 직접 공식 문서를 찾아 해메었다.
(spring 공식문서,baeldung)

값을 전달하기 까지의 과정
setting.gradle -> build.gradle -> yml -> bean 

setting.gradle 에서는 bean 값을 전달하기 까지의 생명주기가 맞지 않아

생명주기가 닿는 build.gradle 을 이용하여 yml 에 값을 전달하요 bean 으로 등록을 함



###  native code 적용기 

~1주 동안 여러 공식문서를 참고하고 블로그등을 참고했지만
최소 설정으로 하려던것이 큰 문제라서 해결을 문했다
이유는 jni 을 적용하려면 %java_home% 이라는 환경 변수를 bin -> / 으로 변경해줘
/include 라는 폴터를 하위 폴더로 잡아줘야 한다는점 입니다.
하지만 기본적으로 java_home 은 기본적으로  /bin 으로 대부분 사용하고 있어 
변경을 하지 않은점 

spriing 벤딩 문서 여러 블로그들 , chatgpt 등 
최소 셋팅으로 할 수 있는 방법을 찾지 못함 

이문제를 해결한 트리거는 멘땅에 헤딩하는 방식으로 해결했습니다. 


커멘드 단에서 직접 컴파일 해서 순서를 경험해 보는것
이 경험 순서를 .gradle 단에서 스크립트로 적용 변경 해서 실행하기 


https://sungcheol-kim.gitbook.io/jni-tutorial
jni cpp 코드 가이드 