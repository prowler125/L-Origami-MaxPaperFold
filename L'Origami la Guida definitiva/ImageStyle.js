function openModal() {
    document.getElementById("Edo").style.display = "block";
}

function closeModal() {
    document.getElementById("Edo").style.display = "none";
}
document.addEventListener("DOMContentLoaded", function() {
    var modal = document.getElementById("Edo");
    var images = document.querySelectorAll(".modal-image");
    var closeBtn = document.querySelector(".close");

    images.forEach(function(_) {
        _.addEventListener("click", function() {
            modal.style.display = "block";
        });
    });

    closeBtn.addEventListener("click", function() {
        modal.style.display = "none";
    });
});