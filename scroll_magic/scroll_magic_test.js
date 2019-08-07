window.onload = function () {
  var controller = new ScrollMagic.Controller();
  var slides = document.getElementsByClassName("slide");
  for(var i = 0; i < slides.length; i++) {
    new ScrollMagic.Scene({
      triggerElement: slides[i],
      triggerHook: "onLeave",
    })
    .setPin(slides[i])
    .addTo(controller);
  }
}
