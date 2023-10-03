let hsbtn = document.getElementById('eye');
let pass = document.getElementById('password');
let userid = document.getElementById('user');
 
// userid.value = 'arnob123';
// pass.value = 'A@123';
function sh(){
    if(pass.type === 'password'){
        pass.setAttribute('type','text');
        hsbtn.src = "eye-line.png";
    }
    else{
        pass.setAttribute('type','password');
        hsbtn.src = "eye-off-line.png";
    }
}
function login(){
    if(userid.value =='arnob123' && pass.value =='A@123'){
        alert('wollcome to home page');
        
    }
    else{
        alert('user and password invalid \nplease entry currect id and password');
        userid.value = "";
        pass.value = "";
        
        
    }
}