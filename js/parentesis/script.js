
const parser = new Parser();


document.querySelector('#btn-submit').addEventListener('click', function(){
    
    let message;
    let str = document.querySelector('input[name="str"]').value;
    
    if( parser.isValid(str) ){
        message = "The string is valid";
    }else{
        message = "The string is not valid";
    }
    alert(message);
    // document.querySelector('input[name="str"]').value = '';
});
