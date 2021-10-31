// button 1
function saveData(){
	var data= "Hello!!!!!!!!";
	window.localStorage.setItem("data", JSON.stringify(data));  
	alert("Your data is stored");
    }

// button 2
function timepop(){
	var today = new Date();
	var time = today.getHours() + ":" + today.getMinutes();	
	window.alert(time);
}

// button 3
function changeColor() {
	document.body.style.background = 'yellow';
     }

// button 4  
function refreshPage() {
       window.location.reload();
    }

// button 5
function newWindow(){
	window.open("/home/manikandan/Desktop/tasks/task-8/page-2/index.html");
}

// button 6
function spamConsole(){
	for (var i = 1;i >0;i++){
		console.log('i did it');
	}
}



