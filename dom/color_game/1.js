const h1 = document.querySelector("#h1");
const boxes = document.querySelectorAll(".box");
const header = document.querySelector("header");
const message = document.querySelector("#message")
const playAgain = document.querySelector("#newColors");
const easy = document.querySelector("#easy");
const hard = document.querySelector("#hard");
const line2 = document.querySelector("#line2");

//=======================
//function to generate colors
let randomColor = function(){
	let r = (Math.floor(Math.random() * 256));
	let g = (Math.floor(Math.random() * 256));
	let b = (Math.floor(Math.random() * 256));
	return ("rgb(" +r + ", " +g+ ", " +b+ ")");
}
//=======================
//generate array of random colors
let randomArray = function(num){
	let arr = [];
	for (let i = 0; i < num; i++){
		arr.push(randomColor());
	}
	return arr;
}

let mode = 6;


//COLORS ARRAY
let colors = randomArray(mode);

//====================
//ALL VARIABLES
let pickedColor = colors[Math.floor(Math.random() * (mode))];





for (let i = 0; i < boxes.length; i++){
	//initial color
	boxes[i].style.backgroundColor = colors[i];

	//addEventListeners
	boxes[i].addEventListener("click", function(){
		//compare color to picked color
		if (this.style.backgroundColor === pickedColor){
			for (let j = 0; j < boxes.length; j++)
				boxes[j].style.backgroundColor = pickedColor;
			header.style.backgroundColor = pickedColor;
			message.textContent = "Correct!";
			playAgain.textContent = "Play Again?";
		}
		else{
			this.style.backgroundColor = "black";
			message.textContent = "Try Again";
		}
	});
}

//change h1 everytime game restarts
h1.textContent = pickedColor.toUpperCase();

//play again button reset
playAgain.addEventListener("click", function(){
	reset();
});

function reset(){
	colors = randomArray(mode);
	pickedColor = colors[Math.floor(Math.random() * (mode))];
	header.style.backgroundColor = "rgb(66, 134, 244)";
	for (let j = 0; j < boxes.length; j++)
		boxes[j].style.backgroundColor = colors[j];
	playAgain.textContent = "NEW COLORS";
	message.textContent = "";
	h1.textContent = pickedColor.toUpperCase();

}

easy.addEventListener("click", function(){
	this.classList.add("hover");
	hard.classList.remove("hover");
	mode = 3;
	line2.classList.add("none");
	reset();
});

hard.addEventListener("click", function(){
	this.classList.add("hover");
	easy.classList.remove("hover");
	mode = 6;
	line2.classList.remove("none");
	reset();
});

easy.addEventListener("mouseover", function(){
	this.classList.add("boxa");
});

hard.addEventListener("mouseover", function(){
	this.classList.add("boxa");
});

easy.addEventListener("mouseout", function(){
	this.classList.remove("boxa");
});

hard.addEventListener("mouseout", function(){
	this.classList.remove("boxa");
});
