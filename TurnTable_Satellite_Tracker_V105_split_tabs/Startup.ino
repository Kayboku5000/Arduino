


void StartupProgram() {

  while ((Compassaverage > 1) && (Compassaverage < 5)) {

    if (Compassaverage > 0 && Compassaverage  < 180) {
      AZforward();
    }

    else if (Compassaverage > 180  && Compassaverage  < 360) {
      AZbackward();
    }
  }

}

//***********************************************************************************
