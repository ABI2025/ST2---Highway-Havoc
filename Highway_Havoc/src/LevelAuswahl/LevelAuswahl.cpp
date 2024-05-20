#include "LevelAuswahl.hpp"

void LevelAuswahl::levelHinzufuegen(int typ)
{
	sf::RectangleShape levelBox;
	levelBox.setPosition(sf::Vector2f(730 / 11, 100));
	levelBox.move((730 / 11 + 50) * this->levelBoxVector.size(), 0);
	levelBox.setSize(sf::Vector2f(50, 50));
	levelBox.setFillColor(sf::Color(0, 0, 0, 0));
	levelBox.setOutlineThickness(3);
	levelBox.setOutlineColor(sf::Color(sf::Color::White));
	this->levelBoxVector.push_back(levelBox);
	sf::Sprite levelIconSprite;
	levelIconSprite.setTexture(this->levelTextureVector[typ]);
	levelIconSprite.setOrigin(levelIconSprite.getGlobalBounds().getSize().x / 2, levelIconSprite.getGlobalBounds().getSize().y / 2);
	float faktor = 50 / levelIconSprite.getGlobalBounds().getSize().y;
	levelIconSprite.setScale(faktor, faktor);
	levelIconSprite.setPosition(levelBox.getGlobalBounds().getPosition().x + levelBox.getGlobalBounds().getSize().x / 2, levelBox.getGlobalBounds().getPosition().y + levelBox.getGlobalBounds().getSize().y / 2);
	this->levelSpriteVector.push_back(levelIconSprite);
}

Level* LevelAuswahl::levelGenerieren(int index)
{
	Level* level_tmp = new Level(this->window, this->eingabeverwaltung, this->musikverwaltung, 1, 20, 1, 1, this->autoWahl, 1, 10, 0, 0, 1);
	if (index == 1) {
		delete level_tmp;
		level_tmp = new Level(this->window, this->eingabeverwaltung, this->musikverwaltung, 1, 20, 2, 1, this->autoWahl, 1, 15, 0, 0, 1);
	}
	if (index == 2) {
		delete level_tmp;
		level_tmp = new Level(this->window, this->eingabeverwaltung, this->musikverwaltung, 2, 20, 3, 1, this->autoWahl, 1, 20, 1, 10, 2);
	}
	if (index == 3) {
		delete level_tmp;
		level_tmp = new Level(this->window, this->eingabeverwaltung, this->musikverwaltung, 2, 20, 4, 1, this->autoWahl, 1, 20, 1, 15, 2);
	}
	if (index == 4) {
		delete level_tmp;
		level_tmp = new Level(this->window, this->eingabeverwaltung, this->musikverwaltung, 2, 20, 5, 1, this->autoWahl, 1, 20, 1, 15, 3);
	}
	return level_tmp;
}

void LevelAuswahl::autoHinzufuegen(int typ, int preis)
{
	sf::RectangleShape autoBox;
	autoBox.setPosition(sf::Vector2f(730 / 11 * 3.4, 230));
	autoBox.move((730 / 11 + 13) * this->autoBoxVector.size(), 0);
	autoBox.setSize(sf::Vector2f(50, 50));
	autoBox.setFillColor(sf::Color(0, 0, 0, 0));
	autoBox.setOutlineThickness(3);
	autoBox.setOutlineColor(sf::Color(sf::Color::White));
	this->autoBoxVector.push_back(autoBox);
	sf::Sprite autoSprite;
	autoSprite.setTexture(this->autoTexturVector[typ]);
	autoSprite.setOrigin(autoSprite.getGlobalBounds().getSize().x / 2, autoSprite.getGlobalBounds().getSize().y / 2);
	float faktor = 50 / autoSprite.getGlobalBounds().getSize().y;
	autoSprite.setScale(faktor, faktor);
	autoSprite.setPosition(autoBox.getGlobalBounds().getPosition().x + autoBox.getGlobalBounds().getSize().x / 2, autoBox.getGlobalBounds().getPosition().y + autoBox.getGlobalBounds().getSize().y / 2);
	this->autoSpriteVector.push_back(autoSprite);
	this->autoPreisVector.push_back(preis);
}

LevelAuswahl::~LevelAuswahl()
{
	delete this->pauseMenue;
	delete this->gewonnenBildschirm;
	delete this->verlorenBildschirm;
}

LevelAuswahl::LevelAuswahl(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, Fortschritt* fortschritt, MusikVerwaltung* musikverwaltung)
{
	this->window = window;
	this->eingabeverwaltung = eingabeverwaltung;
	this->musikverwaltung = musikverwaltung;
	this->pauseMenue = new PauseMenue(window, eingabeverwaltung, musikverwaltung);
	this->fortschritt = fortschritt;
	this->fortschritt->fortschrittLaden();
	this->verlorenBildschirm = new Nachricht(this->window, this->eingabeverwaltung, "Du bist gestorben!", sf::Color(237, 28, 36, 55));
	this->gewonnenBildschirm = new Nachricht(this->window, this->eingabeverwaltung, "Du hast das Level geschafft!", sf::Color(255, 242, 0, 55));

	this->zustaende.pauseMenueAnzeigen = false;
	this->zustaende.pauseMenueAktualisieren = false;
	this->zustaende.levelAuswahlAktualisieren = true;
	this->zustaende.levelAuswahlAnzeigen = true;
	this->zustaende.levelLaeuft = false;
	this->zustaende.levelAnzeigen = false;
	this->zustaende.levelAktualisieren = false;
	this->zustaende.verlorenBildschirmAnzeigen = false;
	this->zustaende.verlorenBildschirmAktualisieren = false;
	this->zustaende.gewonnenBildschirmAnzeigen = false;
	this->zustaende.gewonnenBildschirmAktualisieren = false;

	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}
	if (!this->shopTextur.loadFromFile("./res/grafiken/shop.png"))
	{
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/shop.png)" << std::endl;
	}
	this->shopSprite.setTexture(this->shopTextur);
	float faktorTmp = this->window->getView().getSize().y / this->shopSprite.getGlobalBounds().getSize().y;
	this->shopSprite.setScale(faktorTmp * 2/3 , faktorTmp * 2/3 );
	this->shopSprite.setPosition(this->window->getView().getCenter().x - 253, this->window->getView().getSize().y - this->shopSprite.getGlobalBounds().getSize().y);
	if (!this->levelSchlossTextur.loadFromFile("./res/grafiken/level_schloss.png"))
	{
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/level_schloss.png)" << std::endl;
	}
	this->levelSchlossSprite.setTexture(this->levelSchlossTextur);
	this->levelSchlossSprite.setScale(0.5f, 0.5f);

	if (!this->muenzeTextur.loadFromFile("./res/grafiken/muenze.png"))
	{
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/muenze.png)" << std::endl;
	}
	this->muenzeSprite.setTexture(this->muenzeTextur);
	this->muenzeSprite.setScale(1.5f, 1.5f);
	this->muenzeSprite.setPosition(this->window->getView().getSize().x - this->muenzeSprite.getGlobalBounds().width - 5, 25);

	this->muenzeAutoSprite.setTexture(this->muenzeTextur);
	this->muenzeAutoSprite.setScale(0.5f, 0.5f);

	std::string string_tmp;
	int geld_tmp = this->fortschritt->getGeld();
	do {
		string_tmp.insert(string_tmp.begin(), (char)(geld_tmp % 10 + 48));
		geld_tmp /= 10;
	} while (geld_tmp != 0);
	this->geldText.setFont(this->PixeboyFont);
	this->geldText.setString(string_tmp);
	this->geldText.setFillColor(sf::Color::White);
	this->geldText.setOutlineColor(sf::Color::White);
	this->geldText.setCharacterSize(60);
	this->geldText.setLetterSpacing(1);
	this->geldText.setOrigin(0, this->geldText.getGlobalBounds().getSize().y * 1.5f);
	this->geldText.setPosition(this->muenzeSprite.getGlobalBounds().getPosition().x - this->geldText.getGlobalBounds().getSize().x - 5, this->muenzeSprite.getGlobalBounds().getPosition().y + this->muenzeSprite.getGlobalBounds().getSize().y / 2);

	this->autoPreisText.setFont(this->PixeboyFont);
	this->autoPreisText.setFillColor(sf::Color::White);
	this->autoPreisText.setOutlineColor(sf::Color::White);
	this->autoPreisText.setString("0");
	this->autoPreisText.setCharacterSize(20);
	this->autoPreisText.setLetterSpacing(1);
	this->autoPreisText.setOrigin(0, this->autoPreisText.getGlobalBounds().getSize().y * 1.5f);

	for (int i = 1; i <= 5; i++) {
		sf::Texture texturTmp;
		char pfadTmp[32] = "./res/grafiken/level _cover.png";
		pfadTmp[20] = (char)i + 48;
		if (!texturTmp.loadFromFile(pfadTmp)) {
			std::cout << "Fehler beim laden der Textur (" << pfadTmp << ")" << std::endl;
		}
		this->levelTextureVector.push_back(texturTmp);
	}

	for (int i = 1; i <= 3; i++) {
		sf::Texture texturTmp;
		char pfadTmp[25] = "./res/grafiken/auto";
		pfadTmp[19] = (char)i + 48;
		pfadTmp[20] = '.';
		pfadTmp[21] = 'p';
		pfadTmp[22] = 'n';
		pfadTmp[23] = 'g';
		if (!texturTmp.loadFromFile(pfadTmp)) {
			std::cout << "Fehler beim laden der Textur (" << pfadTmp << ")" << std::endl;
		}
		this->autoTexturVector.push_back(texturTmp);
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
	this->zurueckPfeil.setPosition(10, 25);

	this->levelHinzufuegen(0);
	this->levelHinzufuegen(1);
	this->levelHinzufuegen(2);
	this->levelHinzufuegen(3);
	this->levelHinzufuegen(4);

	this->autoHinzufuegen(0, 0);
	this->autoHinzufuegen(1, 15);
	this->autoHinzufuegen(2, 40);
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
		this->zustaende.verlorenBildschirmAnzeigen = false;
		this->zustaende.verlorenBildschirmAktualisieren = false;
		this->zustaende.gewonnenBildschirmAnzeigen = false;
		this->zustaende.gewonnenBildschirmAktualisieren = false;
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
				this->zustaende.verlorenBildschirmAnzeigen = false;
				this->zustaende.verlorenBildschirmAktualisieren = false;
				this->zustaende.gewonnenBildschirmAnzeigen = false;
				this->zustaende.gewonnenBildschirmAktualisieren = false;
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
				this->zustaende.verlorenBildschirmAnzeigen = false;
				this->zustaende.verlorenBildschirmAktualisieren = false;
				this->zustaende.gewonnenBildschirmAnzeigen = false;
				this->zustaende.gewonnenBildschirmAktualisieren = false;
				this->eingabeverwaltung->aktualisieren();
				this->fortschritt->setGeld(this->fortschritt->getGeld() + this->level->muenzenGesammelt());
				this->fortschritt->fortschrittSpeichern();
				delete this->level;
			}
		}
	}
	if (zustaende.levelAuswahlAktualisieren) {
		this->fortschritt->fortschrittLaden();
		this->auswahlGetroffen = false;
		bool benutztMaus = false;

		int auswahlXAlt = this->auswahlX;												// für die Geräusche
		int auswahlYAlt = this->auswahlY;

		if (this->eingabeverwaltung->getGruppenStatusGeaendert(0) && this->auswahlY > 0) 	//	Die Eingabe überprüfen und die Auswahl anpassen
		{
			this->auswahlY -= 1;
		}
		if (this->eingabeverwaltung->getGruppenStatusGeaendert(2) && this->auswahlY < 2) 	//	Die Eingabe überprüfen und die Auswahl anpassen
		{
			this->auswahlY += 1;
		}
		if (this->eingabeverwaltung->getGruppenStatusGeaendert(1) && this->auswahlX > 0) 	//	Die Eingabe überprüfen und die Auswahl anpassen
		{
			this->auswahlX -= 1;
		}
		if (this->eingabeverwaltung->getGruppenStatusGeaendert(3) && this->auswahlX < this->levelBoxVector.size() - 1) 	//	Die Eingabe überprüfen und die Auswahl anpassen
		{
			this->auswahlX += 1;
		}
		if (this->auswahlY == 2 && this->auswahlX > 2) {
			this->auswahlX = 2;
		}
		if (this->eingabeverwaltung->mausPositionInFlaeche(this->zurueckPfeil.getGlobalBounds())) {
			this->auswahlY = 0;
			this->auswahlX = 0;
			benutztMaus = true;
		}
		for (int i = 0; i < this->levelBoxVector.size(); i++) {
			if (this->eingabeverwaltung->mausPositionInFlaeche(this->levelBoxVector[i].getGlobalBounds())) {
				this->auswahlY = 1;
				this->auswahlX = i;
				benutztMaus = true;
			}
		}
		for (int i = 0; i < this->autoBoxVector.size(); i++) {
			if (this->eingabeverwaltung->mausPositionInFlaeche(this->autoBoxVector[i].getGlobalBounds())) {
				this->auswahlY = 2;
				this->auswahlX = i;
				benutztMaus = true;
			}
		}
		if (this->eingabeverwaltung->getGruppenStatusGeaendert(4) || (this->eingabeverwaltung->getMausTastenStatusGeandertIndex(0) && benutztMaus == true)) {
			this->auswahlGetroffen = true;
			if (this->auswahlX <= this->fortschritt->getLevelFreigeschaltet() && this->auswahlY == 1) {
				this->zustaende.pauseMenueAnzeigen = false;
				this->zustaende.pauseMenueAktualisieren = false;
				this->zustaende.levelAuswahlAktualisieren = false;
				this->zustaende.levelAuswahlAnzeigen = false;
				this->zustaende.levelLaeuft = true;
				this->zustaende.levelAnzeigen = true;
				this->zustaende.levelAktualisieren = true;
				this->zustaende.verlorenBildschirmAnzeigen = false;
				this->zustaende.verlorenBildschirmAktualisieren = false;
				this->zustaende.gewonnenBildschirmAnzeigen = false;
				this->zustaende.gewonnenBildschirmAktualisieren = false;
				this->level = this->levelGenerieren(this->auswahlX);
			}
			if (this->fortschritt->getGeld() >= this->autoPreisVector[auswahlX] && this->auswahlX == this->fortschritt->getAutoFreigeschaltet() + 1 && this->auswahlY == 2) {
				this->fortschritt->setGeld(this->fortschritt->getGeld() - this->autoPreisVector[auswahlX]);
				this->fortschritt->setAutoFreigeschaltet(this->auswahlX);
				this->fortschritt->fortschrittSpeichern();
			}
			if (this->auswahlX <= this->fortschritt->getAutoFreigeschaltet() && this->auswahlY == 2) {
				this->autoWahl = this->auswahlX;
			}
			this->musikverwaltung->musikMenueKlickStarten();
		}
		if (auswahlX != auswahlXAlt || auswahlY != auswahlYAlt) this->musikverwaltung->musikMenueHoverStarten();
	}
	if (zustaende.levelAktualisieren) {
		this->level->aktualisieren();
		if (this->level->getUnterbrechung()) {
			int unterbrechungsgrund = this->level->getUnterbrechungsgrund();
			if (unterbrechungsgrund == 0) {
				this->zustaende.pauseMenueAnzeigen = false;
				this->zustaende.pauseMenueAktualisieren = false;
				this->zustaende.levelAuswahlAktualisieren = false;
				this->zustaende.levelAuswahlAnzeigen = false;
				this->zustaende.levelLaeuft = false;
				this->zustaende.levelAnzeigen = true;
				this->zustaende.levelAktualisieren = false;
				this->zustaende.verlorenBildschirmAnzeigen = true;
				this->zustaende.verlorenBildschirmAktualisieren = true;
				this->zustaende.gewonnenBildschirmAnzeigen = false;
				this->zustaende.gewonnenBildschirmAktualisieren = false;
				this->musikverwaltung->musikLevelverlorenStarten();
			}
			if (unterbrechungsgrund == 1) {
				this->zustaende.pauseMenueAnzeigen = false;
				this->zustaende.pauseMenueAktualisieren = false;
				this->zustaende.levelAuswahlAktualisieren = false;
				this->zustaende.levelAuswahlAnzeigen = false;
				this->zustaende.levelLaeuft = false;
				this->zustaende.levelAnzeigen = true;
				this->zustaende.levelAktualisieren = false;
				this->zustaende.verlorenBildschirmAnzeigen = false;
				this->zustaende.verlorenBildschirmAktualisieren = false;
				this->zustaende.gewonnenBildschirmAnzeigen = true;
				this->zustaende.gewonnenBildschirmAktualisieren = true;
				this->musikverwaltung->musikLevelgeschafftStarten();
			}
		}
	}
	if (this->zustaende.verlorenBildschirmAktualisieren) {
		this->verlorenBildschirm->aktualisieren();
		if (this->verlorenBildschirm->getAuswahlGetroffen()) {
			this->zustaende.pauseMenueAnzeigen = false;
			this->zustaende.pauseMenueAktualisieren = false;
			this->zustaende.levelAuswahlAktualisieren = true;
			this->zustaende.levelAuswahlAnzeigen = true;
			this->zustaende.levelLaeuft = false;
			this->zustaende.levelAnzeigen = false;
			this->zustaende.levelAktualisieren = false;
			this->zustaende.verlorenBildschirmAnzeigen = false;
			this->zustaende.verlorenBildschirmAktualisieren = false;
			this->zustaende.gewonnenBildschirmAnzeigen = false;
			this->zustaende.gewonnenBildschirmAktualisieren = false;
			this->fortschritt->setGeld(this->fortschritt->getGeld() + this->level->muenzenGesammelt());
			delete this->level;
			this->fortschritt->fortschrittSpeichern();
		}
	}
	if (this->zustaende.gewonnenBildschirmAktualisieren) {
		this->gewonnenBildschirm->aktualisieren();
		if (this->gewonnenBildschirm->getAuswahlGetroffen()) {
			this->zustaende.pauseMenueAnzeigen = false;
			this->zustaende.pauseMenueAktualisieren = false;
			this->zustaende.levelAuswahlAktualisieren = true;
			this->zustaende.levelAuswahlAnzeigen = true;
			this->zustaende.levelLaeuft = false;
			this->zustaende.levelAnzeigen = false;
			this->zustaende.levelAktualisieren = false;
			this->zustaende.verlorenBildschirmAnzeigen = false;
			this->zustaende.verlorenBildschirmAktualisieren = false;
			this->zustaende.gewonnenBildschirmAnzeigen = false;
			this->zustaende.gewonnenBildschirmAktualisieren = false;
			this->fortschritt->setGeld(this->fortschritt->getGeld() + /*this->levelVector[this->auswahlX]*/this->level->muenzenGesammelt());
			delete this->level;
			if (this->fortschritt->getLevelFreigeschaltet() == this->auswahlX) this->fortschritt->setLevelFreigeschaltet(this->auswahlX + 1);
			this->fortschritt->fortschrittSpeichern();
		}
	}
}

void LevelAuswahl::anzeigen()
{
	this->window->setView(sf::View(sf::Vector2f(this->window->getView().getSize().x / 2, this->window->getView().getSize().y / 2), sf::Vector2f(this->window->getView().getSize().x, this->window->getView().getSize().y)));
	if (zustaende.levelAuswahlAnzeigen) {
		this->window->clear(sf::Color(55, 166, 166, 255));
		this->window->draw(shopSprite);
		this->zurueckPfeil.setFillColor(sf::Color::White);
		this->zurueckPfeil.setOutlineColor(sf::Color::White);
		if (this->auswahlY == 0) {
			this->zurueckPfeil.setFillColor(sf::Color::Red);
			this->zurueckPfeil.setOutlineColor(sf::Color::Red);
		}
		this->window->draw(this->zurueckPfeil);
		this->window->draw(this->titelText);
		for (int i = 0; i < this->levelBoxVector.size(); i++) {
			this->levelBoxVector[i].setOutlineColor(sf::Color::White);
			if (i == this->auswahlX && this->auswahlY == 1) this->levelBoxVector[i].setOutlineColor(sf::Color::Red);
			this->levelSchlossSprite.setPosition(this->levelSpriteVector[i].getPosition() + sf::Vector2f(2, 0));
			this->window->draw(this->levelBoxVector[i]);
			this->window->draw(this->levelSpriteVector[i]);
			if (i > this->fortschritt->getLevelFreigeschaltet()) this->window->draw(this->levelSchlossSprite);
		}
		std::string string_tmp;
		int geld_tmp = this->fortschritt->getGeld();
		do {
			string_tmp.insert(string_tmp.begin(), (char)(geld_tmp % 10 + 48));
			geld_tmp /= 10;
		} while (geld_tmp != 0);
		this->geldText.setString(string_tmp);
		this->geldText.setPosition(this->muenzeSprite.getGlobalBounds().getPosition().x - this->geldText.getGlobalBounds().getSize().x - 5, this->muenzeSprite.getGlobalBounds().getPosition().y + this->muenzeSprite.getGlobalBounds().getSize().y / 2);
		this->window->draw(this->muenzeSprite);
		this->window->draw(this->geldText);
		for (int i = 0; i < this->autoBoxVector.size(); i++) {
			this->autoBoxVector[i].setOutlineColor(sf::Color::White);
			if (i == this->autoWahl) this->autoBoxVector[i].setOutlineColor(sf::Color::Green);
			if (i == this->auswahlX && this->auswahlY == 2) this->autoBoxVector[i].setOutlineColor(sf::Color::Red);
			this->levelSchlossSprite.setPosition(this->autoSpriteVector[i].getPosition() + sf::Vector2f(2, 0));
			this->muenzeAutoSprite.setPosition(this->autoSpriteVector[i].getPosition() + sf::Vector2f(15, 30));
			std::string string_tmp2;
			int geld_tmp2 = this->autoPreisVector[i];
			do {
				string_tmp2.insert(string_tmp2.begin(), (char)(geld_tmp2 % 10 + 48));
				geld_tmp2 /= 10;
			} while (geld_tmp2 != 0);
			this->autoPreisText.setString(string_tmp2);
			this->autoPreisText.setPosition(this->muenzeAutoSprite.getGlobalBounds().getPosition().x - this->autoPreisText.getGlobalBounds().getSize().x - 5, this->muenzeAutoSprite.getGlobalBounds().getPosition().y + this->muenzeAutoSprite.getGlobalBounds().getSize().y / 2);
			this->window->draw(this->autoBoxVector[i]);
			this->window->draw(this->autoSpriteVector[i]);
			if (i > this->fortschritt->getAutoFreigeschaltet()) {
				this->window->draw(this->levelSchlossSprite); 
				this->window->draw(this->muenzeAutoSprite);
				this->window->draw(this->autoPreisText);
			}
		}
	}
	if (this->zustaende.levelAnzeigen) this->level->anzeigen();
	if (this->zustaende.pauseMenueAnzeigen)	this->pauseMenue->anzeigen();
	if (this->zustaende.verlorenBildschirmAnzeigen) this->verlorenBildschirm->anzeigen();
	if (this->zustaende.gewonnenBildschirmAnzeigen) this->gewonnenBildschirm->anzeigen();



	//this->muenzeSprite.setPosition(this->window->getView().getSize().x - this->muenzeSprite.getGlobalBounds().width, this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
	//this->geldText.setPosition(this->muenzeSprite.getGlobalBounds().getPosition().x - this->geldText.getGlobalBounds().getSize().x - 5, this->muenzeSprite.getGlobalBounds().getPosition().y + this->muenzeSprite.getGlobalBounds().getSize().y / 2);
}

bool LevelAuswahl::getAuswahlGetroffen()
{
	return this->auswahlGetroffen;
}

unsigned short LevelAuswahl::getAuswahlY()
{
	return this->auswahlY;
}

unsigned short LevelAuswahl::getAuswahlX()
{
	return this->auswahlX;
}

bool LevelAuswahl::getUnterbrechung()
{
	return this->unterbrechung;
}

int LevelAuswahl::getUnterbrechungsgrund()
{
	return this->unterbrechungsgrund;
}