const images = document.querySelectorAll('.image_column > img');
const modal = document.createElement('div');
modal.classList.add('modal')
document.body.appendChild(modal);

images.forEach((image) => {
    image.addEventListener('click', (e) => {
        const imageSrc = e.target.src;
        const modalImage = document.createElement('img');
        modalImage.src = imageSrc;
        modal.appendChild(modalImage);
        modal.style.display = 'flex';
        modalImage.addEventListener('click', (e) => {
            modalImage.style.transform = 'scale(1.5)';
            modalImage.style.opacity = '0';
            setTimeout(() => {
                modal.style.display = 'none';
                modal.removeChild(modalImage);
                modalImage.style.transform = 'scale(1)';
                modalImage.style.opacity = '1';
            }, 300);
        });
    });
});

modal.addEventListener('click', (e) => {
    if (e.target === modal) {
        const modalImage = modal.querySelector('img');
        modalImage.style.transform = 'scale(1.5)';
        modalImage.style.opacity = '0';
        setTimeout(() => {
            modal.style.display = 'none';
            modal.removeChild(modalImage);
            modalImage.style.transform = 'scale(1)';
            modalImage.style.opacity = '1';
        }, 300);
    }
});

const openmenu = () => {
    let menu = document.querySelector(".openNav");
    menu.style.display = menu.style.display == "block" ? "none" : "block";
}
