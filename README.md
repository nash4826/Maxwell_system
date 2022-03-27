# 관리 프로그램

# Web Page

https://nash4826.github.io/Maxwell_system/

# 현황

<ol>
  <li>css 리팩토링, html 클래스명 짓기 완료.(03-19)</li>
  <li>전력 현황 페이지 chart.js 활용하여 작업중 (03-22 ~ )</li>
  <li>c_json 파일 작업, 컴파일 완료 (03-27)</li>
  <li>json 파일에 있는 한글이 깨지는 현상 발생(수정중)</li>
</ol>

## 계획 변경

C 언어로만 관리 시스템을 만들 계획이었으나, 유저 친화적인 프로젝트 구현 계획으로 전환

## blueprint

1. c언어를 활용하여 전력 데이터를 수집하고, ESS의 충전데이터을 무작위(rand)로 받아 축적.
2. 데이터를 json 파일로 변환하여, 서버단에 json 전송
3. 클라이언트가 서버에게 json 요청
4. 서버는 클라이언트에 json 전달
5. json의 데이터를 화면에 출력
6. 전력 거래 페이지에서 카카오 결제 API 활용(테스트 고려중)

## 기술

FrontEnd : html,css,js

FrontEnd-framework : Bootstrap

BackEnd : js or python

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
