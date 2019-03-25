const lis = document.querySelectorAll("li");
const xxx = document.querySelectorAll(".xxx");
const inp = document.querySelector("#inp");
const ul = document.querySelector("ul");


// click listener for li
for (let i = 0; i < lis.length; i++){
	lis[i].addEventListener("click", function(){
		this.classList.toggle("cross");
	});
}

//click listener for 'X' on lis
for (let i = 0; i < xxx.length; i++){
	xxx[i].addEventListener("click", function(e){
		lis[i].classList.add("hide");
		event.stopPropagation();

	});
}

inp.addEventListener("keypress", function(event){
	if (event.which === 13){
		let newTodo = "<span>X</span> " + this.value;
		let li = document.createElement("li");
		li.innerHTML = newTodo;
		ul.appendChild(li);
	}
});
