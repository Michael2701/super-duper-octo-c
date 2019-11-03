const form = document.querySelector('#form');
form.addEventListener('submit', function(e){
    e.preventDefault();
    let flag = true;
    const data = document.querySelectorAll('.form-control').forEach(function(el){
        if (!el.checkValidity()){
            flag = false;
            el.nextElementSibling.innerHTML = el.validationMessage;
            el.classList.add('error');
        }
    });
    if( flag ) form.submit()
});

document.querySelectorAll('input.form-control').forEach(function(el){
    el.addEventListener('keyup', function(e){
        if (!el.checkValidity()){
            el.nextElementSibling.innerHTML = el.validationMessage;
            el.classList.remove('valid');               
            el.classList.add('error');
        }else{
            el.nextElementSibling.innerHTML = '';
            el.classList.remove('error');
            el.classList.add('valid');
        }
    });
});

document.querySelectorAll('select.form-control').forEach(function(el){
    el.addEventListener('change', function(e){
        if (!el.checkValidity()){
            el.nextElementSibling.innerHTML = el.validationMessage;
            el.classList.remove('valid');               
            el.classList.add('error');
        }else{
            el.nextElementSibling.innerHTML = '';
            el.classList.remove('error');
            el.classList.add('valid');
        }
    });
});

setTimeout(()=>{
    document.querySelector('#cover').style.display = 'block';
},5000);
setTimeout(()=>{
    document.querySelector('#cover').style.display = 'none';
},10000)