
function charge(data) {
  /*ESS 충전 그래프 */
  const essChargeNumber = document.querySelector('.ess-charge-number');
  essChargeNumber.innerText = (12.8 * (data.ESS * 0.01)).toFixed(1);
  const ctx = document.getElementById("ess-graph");
  const essData = {
    labels: [
      '충전',
    ],
    datasets: [{
      label: 'ESS',
      data: [data.ESS,100-data.ESS], // ess-charge data, empty(100 - essChargeData)
      backgroundColor: [
        'rgb(54, 162, 235)',
        'rgb(255,255,255)'
      ],
      hoverOffset: 4
    }]
  };
  const essConfig = {
    type: 'doughnut',
    data: essData,
  };

  const essCharge = new Chart(ctx,essConfig);
}

function powerStatus(data) {
  const kWh = document.querySelector('.kWh');
  const Hz = document.querySelector('.Hz');
  const LV = document.querySelector('.LV');
  const PV = document.querySelector('.PV');
  const AC = document.querySelector('.AC');
  const temp = document.querySelector('.temp');
  const cos = document.querySelector('.cos');
  const realP = document.querySelector('.realP');
  const reactiveP = document.querySelector('.reactiveP');

  kWh.innerText = data.accumulated_power;
  Hz.innerText = data.frequency;
  LV.innerText = data.line_voltage;
  PV.innerHTML = data.phase_voltage;
  AC.innerText = data.average_current;
  temp.innerText = data.temperature;
  cos.innerText = data.power_factor;
  realP.innerText = data.real_power;
  reactiveP.innerText = data.reactive_power;
}


fetch(`../json/status.json`)
  .then(res => res.json())
  .then(data => {
    console.log(data);
    powerStatus(data);
    charge(data);
  });