const hr = document.querySelector("#hr");
const min = document.querySelector("#min");
const sec = document.querySelector("#sec");

const inputs = document.querySelectorAll(".inp");
const buttons = document.querySelectorAll(".button");


for (let i = 0; i < inputs.length; i++){
	inputs[i].addEventListener("change", function(){
		if (i == 0)
			hr.textContent = inputs[i].value;
		else if (i == 1)
			min.textContent = inputs[i].value;
		else
			sec.textContent = inputs[i].value;
	});
}

