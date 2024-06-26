package de.clientside;



import de.tiere.PigTooFatListener;
import de.tiere.Schwein;

public class Main {

	Metzger metzger = new Metzger();
	Spediteur spediteur = new Spediteur();
	public static void main(String[] args) {
		new Main().run();
	}

	private void run() {
		Schwein schwein = new Schwein("Miss Piggy");
		schwein.addPigTooFatListener(new SchweineMetzgerAdapter());
		schwein.addPigTooFatListener(t->spediteur.fahren(t));
		for (int i = 0; i < 11; i++) {
			schwein.fuettern();
		}


	}

	class SchweineMetzgerAdapter implements PigTooFatListener {

		@Override
		public void pigTooFat(final Schwein dickesSchwein) {
			metzger.schlachten(dickesSchwein);
		}
	}
}

class Metzger  {


	public void schlachten(final Object dickesSchwein) {
		System.out.println("Messer wetz!");
	}
}

class Spediteur {
	public void fahren(Object ware) {
		System.out.println("wir fahren auf der Autobahn");
	}
}



