function validate1(event)
{
    var target = event.srcElement;
    var id = String(target.innerHTML);
    if (id === 'Derrik Rose')
    {
        document.getElementById(id).style.backgroundColor = 'green';
        document.getElementById('response1').innerHTML = 'Correct!';
    }
    else
    {
        document.getElementById(id).style.backgroundColor = 'red';
        document.getElementById('response1').innerHTML = 'Incorrect';
    }
}

function validate2()
{
    var answer = document.querySelector('#text_written').value;
    if (answer.toLocaleLowerCase() === 'michael jordan')
    {
        document.getElementById('text_written').style.backgroundColor = 'green';
        document.getElementById('response2').innerHTML = 'Correct!';
    }
    else
    {
        document.getElementById('text_written').style.backgroundColor = 'red';
        document.getElementById('response2').innerHTML = 'Inorrect';
    }
}