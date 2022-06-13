# 관리 프로그램 (Prototype)

# Web Page

<strong>express 작업중</strong>

https://power-management.herokuapp.com/

# 현황

<ol>
  <li>css 리팩토링, html 클래스명 짓기 완료.</li>
  <li>전력 현황 페이지 chart.js 활용하여 작업중 </li>
  <li>c_json 파일 작업, 컴파일 완료</li>
  <li>json 파일에 있는 한글이 깨지는 현상 발생(영어 변환 완료)</li>
  <li>express를 설치 및 간단한 get 매서드 사용.</li>
  <li>파일 구조를 전부 수정함. template를 'html'로 사용. </li>
  <li>json파일을 읽어와 innerText를 이용하여 값 할당</li>
  <li>임시 배포 완료</li>

  <li>login form 제작중(우선 프레임만)</li>
</ol>

## blueprint

1. c언어를 활용하여 전력 데이터를 수집하고, ESS의 충전데이터을 무작위(rand)로 받아 축적.
2. 데이터를 json 파일로 변환하여, 서버단에 json 전송
3. 클라이언트가 서버에게 json 요청
4. 서버는 클라이언트에 json 전달
5. json의 데이터를 화면에 출력
6. 전력 거래 페이지에서 카카오 결제 API 활용 고려(테스트 고려중)

## 기술

C language

FrontEnd : html,css,js

FrontEnd-framework : Bootstrap

BackEnd : js(express)

opensource :

<ol> 
  <li>chart.js : https://github.com/chartjs/Chart.js</li>
  <li>parson : https://github.com/kgabis/parson</li>
</ol>

## 한계

> 1. 전반적인 web 지식과 프로그래밍 기술
>
> 2. 실시간 동기화 문제
>
> 3. 데이터를 수집하기 위해서는 IoT 디바이스와 데이터를 수집할 환경이 필요하나, 현실적으로 어려움을 느껴 간단한 rand 함수로 대체.

## 어려움

1. 서버에 대한 지식이 부족하다.

   > get,post를 이용하여 Page를 불러오고, bodyParser를 통해 로그인 폼의 데이터를 출력하는 단계까지 진행했으나 express, 서버에 대한 깊은 개념은 이해 하기 어려웠다.네트워크가 중요한 것 같다.
