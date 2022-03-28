const clock = document.querySelector(".clock");
function getClock(){
  const date = new Date();
  clock.innerText = `현재 시간 ${date.getHours()} : ${date.getMinutes()} : ${date.getSeconds()}`;
}

getClock();
setInterval(getClock,1000);
