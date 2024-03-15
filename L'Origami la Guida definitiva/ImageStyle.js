var modal= document.getElementById('PeriodoEdo');
var img=
document.getElementById('PeriodoEdo');
var modalImg = document.getElementById("PeriodoEdo");
var captionText = document.getElementById("caption");
img.onclick = function(){
    modal.style.display = "block";
    modalImg.src = this.src;
    captionText.innerHTML = this.alt;
    }
var span = document.getElementsByClassName("close")[0];
span.onclick = function() {
    modal.style.display = "none";
}