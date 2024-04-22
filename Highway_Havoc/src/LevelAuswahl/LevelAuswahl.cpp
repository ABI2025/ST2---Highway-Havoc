#include "LevelAuswahl.hpp"

void LevelAuswahl::levelHinzufuegen(Level* level)
{
	sf::RectangleShape levelBox;
	levelBox.setPosition(sf::Vector2f(730 / 11, 100));
	levelBox.move((730 / 11 + 50) * this->levelBoxVector.size(), 0);
	levelBox.setSize(sf::Vector2f(50, 50));
	levelBox.setFillColor(sf::Color(0, 0, 0, 0));
	levelBox.setOutlineThickness(3);
	levelBox.setOutlineColor(sf::Color(sf::Color::White));
	this->levelBoxVector.push_back(levelBox);
	this->levelVector.push_back(level);
}

Level* LevelAuswahl::levelGenerieren(int index)
{
	Level* level_tmp = new Level1(this->window, this->eingabeverwaltung);
	if (index == 2) {
		delete level_tmp;
		level_tmp = new Level2(this->window, this->eingabeverwaltung);
	}
	return level_tmp;
}

LevelAuswahl::~LevelAuswahl()
{
	delete this->eingabeverwaltung;
	this->eingabeverwaltung = nullptr;
}

LevelAuswahl::LevelAuswahl(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung)
{
	this->window = window;
	this->eingabeverwaltung = eingabeverwaltung;
	this->pauseMenue = new PauseMenue(window, eingabeverwaltung);

	this->zustaende.pauseMenueAnzeigen = false;
	this->zustaende.pauseMenueAktualisieren = false;
	this->zustaende.levelAuswahlAktualisieren = true;
	this->zustaende.levelAuswahlAnzeigen = true;
	this->zustaende.levelLaeuft = false;
	this->zustaende.levelAnzeigen = false;
	this->zustaende.levelAktualisieren = false;

	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}
	sf::Texture level1Textur;
	if (!level1Textur.loadFromFile("./res/grafiken/level1_cover.png"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/grafiken/level1_cover.png)" << std::endl;
	}
	this->levelTextureVector.push_back(level1Textur);
	sf::Texture level2Textur;
	if (!level2Textur.loadFromFile("./res/grafiken/level2_cover.png"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/grafiken/level2_cover.png)" << std::endl;
	}
	this->levelTextureVector.push_back(level2Textur);
	sf::Texture level3Textur;
	if (!level3Textur.loadFromFile("./res/grafiken/level3_cover.png"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/grafiken/level3_cover.png)" << std::endl;
	}
	this->levelTextureVector.push_back(level3Textur);
	for (int i = 0; i < this->levelTextureVector.size(); i++) {
		sf::Sprite levelIconSprite;
		levelIconSprite.setTexture(this->levelTextureVector[i]);
		levelIconSprite.setPosition(sf::Vector2f(730 / 11, 100));
		levelIconSprite.move((730 / 11 + 50) * i, 0);
		this->levelSpriteVector.push_back(levelIconSprite);
	}

	this->titelText.setFont(PixeboyFont);
	this->titelText.setFillColor(sf::Color::White);
	this->titelText.setOutlineColor(sf::Color::White);
	this->titelText.setCharacterSize(60);
	this->titelText.setLetterSpacing(1);
	this->titelText.setString("Level Auswahl");
	this->titelText.setPosition({ window->getSize().x / 2 - titelText.getGlobalBounds().width / 2, 0 });

	this->zurueckPfeil.setPointCount(7);
	this->zurueckPfeil.setPoint(0, sf::Vector2f(0, 50));
	this->zurueckPfeil.setPoint(1, sf::Vector2f(50, 0));
	this->zurueckPfeil.setPoint(2, sf::Vector2f(50, 25));
	this->zurueckPfeil.setPoint(3, sf::Vector2f(100, 25));
	this->zurueckPfeil.setPoint(4, sf::Vector2f(100, 75));
	this->zurueckPfeil.setPoint(5, sf::Vector2f(50, 75));
	this->zurueckPfeil.setPoint(6, sf::Vector2f(50, 100));
	this->zurueckPfeil.setScale(sf::Vector2f(0.35f, 0.35f));
	this->zurueckPfeil.setPosition(0, 25);

	this->levelHinzufuegen(this->levelGenerieren(1));
	this->levelHinzufuegen(this->levelGenerieren(2));
	this->levelHinzufuegen(this->levelGenerieren(1));
}

void LevelAuswahl::aktualisieren()
{
	this->unterbrechung = false;
	this->eingabeverwaltung->aktualisieren();
	if (this->eingabeverwaltung->getTastenStatusGeandertIndex(10) && zustaende.levelLaeuft) {
		this->zustaende.pauseMenueAnzeigen = true;
		this->zustaende.pauseMenueAktualisieren = true;
		this->zustaende.levelAuswahlAktualisieren = false;
		this->zustaende.levelAuswahlAnzeigen = false;
		this->zustaende.levelLaeuft = true;
		this->zustaende.levelAnzeigen = true;
		this->zustaende.levelAktualisieren = false;
	}
	if (this->zustaende.pauseMenueAktualisieren) {
		this->pauseMenue->aktualisieren();
		if (this->pauseMenue->getAuswahlGetroffen()) {
			int auswahl = this->pauseMenue->getAuswahl();
			if (auswahl == 0) {
				this->zustaende.pauseMenueAnzeigen = false;
				this->zustaende.pauseMenueAktualisieren = false;
				this->zustaende.levelAuswahlAktualisieren = false;
				this->zustaende.levelAuswahlAnzeigen = false;
				this->zustaende.levelLaeuft = true;
				this->zustaende.levelAnzeigen = true;
				this->zustaende.levelAktualisieren = true;
			}
			if (auswahl == 1) {
				this->unterbrechung = true;
				this->unterbrechungsgrund = 0;
			}
			if (auswahl == 2) {
				this->zustaende.pauseMenueAnzeigen = false;
				this->zustaende.pauseMenueAktualisieren = false;
				this->zustaende.levelAuswahlAktualisieren = true;
				this->zustaende.levelAuswahlAnzeigen = true;
				this->zustaende.levelLaeuft = false;
				this->zustaende.levelAnzeigen = false;
				this->zustaende.levelAktualisieren = false;
				this->eingabeverwaltung->aktualisieren();
				delete this->levelVector[this->auswahl - 1];
				this->levelVector[this->auswahl - 1] = this->levelGenerieren(this->auswahl);
			}
		}
	}
	if (zustaende.levelAuswahlAktualisieren) {
		this->auswahlGetroffen = false;
		bool benutztMaus = false;
		if (this->eingabeverwaltung->getGruppenStatusGeaendert(0) && this->auswahl > 0) 	//	Die Eingabe überprüfen und die Auswahl anpassen
		{
			this->auswahl -= 1;
		}
		if (this->eingabeverwaltung->getGruppenStatusGeaendert(2) && this->auswahl < this->levelBoxVector.size()) 	//	Die Eingabe überprüfen und die Auswahl anpassen
		{
			this->auswahl += 1;
		}
		if (this->eingabeverwaltung->mausPositionInFlaeche(this->zurueckPfeil.getGlobalBounds())) {
			this->auswahl = 0;
			benutztMaus = true;
		}
		for (int i = 0; i < this->levelBoxVector.size(); i++) {
			if (this->eingabeverwaltung->mausPositionInFlaeche(this->levelBoxVector[i].getGlobalBounds())) {
				this->auswahl = i + 1;
				benutztMaus = true;
			}
		}
		if (this->eingabeverwaltung->getGruppenStatusGeaendert(4) || (this->eingabeverwaltung->getMausTastenStatusGeandertIndex(0) && benutztMaus == true)) {
			this->auswahlGetroffen = true;
			if (this->auswahl != 0) {
				this->zustaende.pauseMenueAnzeigen = false;
				this->zustaende.pauseMenueAktualisieren = false;
				this->zustaende.levelAuswahlAktualisieren = false;
				this->zustaende.levelAuswahlAnzeigen = false;
				this->zustaende.levelLaeuft = true;
				this->zustaende.levelAnzeigen = true;
				this->zustaende.levelAktualisieren = true;
				//return;
			}
		}
	}
	if (zustaende.levelAktualisieren) {
		this->levelVector[this->auswahl - 1]->aktualisieren();
		if (this->levelVector[this->auswahl - 1]->getUnterbrechung()) {
			if (this->levelVector[this->auswahl - 1]->getUnterbrechungsgrund() == 0) {
				this->zustaende.pauseMenueAnzeigen = false;
				this->zustaende.pauseMenueAktualisieren = false;
				this->zustaende.levelAuswahlAktualisieren = true;
				this->zustaende.levelAuswahlAnzeigen = true;
				this->zustaende.levelLaeuft = false;
				this->zustaende.levelAnzeigen = false;
				this->zustaende.levelAktualisieren = false;
				this->eingabeverwaltung->aktualisieren();
				delete this->levelVector[this->auswahl - 1];
				this->levelVector[this->auswahl - 1] = this->levelGenerieren(this->auswahl);
			}
		}
	}
}

void LevelAuswahl::anzeigen()
{
	this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, this->window->getView().getSize().y / 2), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
	if (zustaende.levelAuswahlAnzeigen) {
		this->window->clear(sf::Color(55, 166, 166, 255));
		this->zurueckPfeil.setFillColor(sf::Color::White);
		this->zurueckPfeil.setOutlineColor(sf::Color::White);
		if (this->auswahl == 0) {
			this->zurueckPfeil.setFillColor(sf::Color::Red);
			this->zurueckPfeil.setOutlineColor(sf::Color::Red);
		}
		this->window->draw(this->zurueckPfeil);
		this->window->draw(this->titelText);
		for (int i = 0; i < this->levelBoxVector.size(); i++) {
			this->levelBoxVector[i].setOutlineColor(sf::Color::White);
			if (i == this->auswahl - 1) this->levelBoxVector[i].setOutlineColor(sf::Color::Red);
			this->window->draw(this->levelBoxVector[i]);
			this->window->draw(this->levelSpriteVector[i]);
		}
	}
	if (this->zustaende.levelAnzeigen) this->levelVector[this->auswahl - 1]->anzeigen();
	if (this->zustaende.pauseMenueAnzeigen)	this->pauseMenue->anzeigen();
}

bool LevelAuswahl::getAuswahlGetroffen()
{
	return this->auswahlGetroffen;
}

unsigned short LevelAuswahl::getAuswahl()
{
	return this->auswahl;
}

bool LevelAuswahl::getUnterbrechung()
{
	return this->unterbrechung;
}

int LevelAuswahl::getUnterbrechungsgrund()
{
	return this->unterbrechungsgrund;
}