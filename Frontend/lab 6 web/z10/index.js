let button = document.querySelector("button")
let ship = document.querySelector("#ship")
button.onclick = function() 
{
    button.textContent = "Поплыли!"
    button.style.borderRadius = "20px 20px 100px 100px"
    ship.style.transform = "translateX(" + 1500 + "px)"
    board.style.transform = "rotate(" + 90 + "deg)"
    sail_one.style.transform = "rotateX(" + 0 + "deg)"
    sail_two.style.transform = "rotateX(" + 0 + "deg)"
}