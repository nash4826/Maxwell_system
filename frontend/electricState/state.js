/*ESS 충전 그래프 */
const ctx = document.getElementById("ess-graph");
const essData = {
  labels: [
    '충전',
  ],
  datasets: [{
    label: 'ESS',
    data: [70,30], // ess-charge data, empty(100 - essChargeData)
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


