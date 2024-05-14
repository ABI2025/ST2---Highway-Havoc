#include "Spieler.hpp"
Spieler::~Spieler()
{
}

Spieler::Spieler()
{
}

Spieler::Spieler(sf::RenderWindow* window, EingabeVerwaltung* eingabeverwaltung, sf::Texture* textur, Eigenschaften eigenschaften)
{
	this->window = window;
	this->textur = *textur;
	this->sprite.setTexture(this->textur);
	sprite.setOrigin(sprite.getGlobalBounds().getSize().x / 2, sprite.getGlobalBounds().getSize().y / 2);
	float faktor = 57.2f / this->sprite.getGlobalBounds().getSize().x;
	sprite.setScale(faktor, faktor);
	this->sprite.setPosition(this->window->getView().getSize().x / 2, this->window->getView().getSize().y / 2);
	geschwindigkeit = 1;
	this->eingabeverwaltung = eingabeverwaltung;
	this->eigenschaften = eigenschaften;

	if (!this->tachoTextur.loadFromFile("./res/grafiken/tacho.png")) {
		std::cout << "Fehler beim laden der Datei. (./res/grafiken/tacho.png)" << std::endl;
	}
	this->tachoSprite.setTexture(this->tachoTextur);
	this->tachoSprite.setScale(2.2f, 2.2f);

	if (!this->tachoZeigerTextur.loadFromFile("./res/grafiken/tachoZeiger.png")) {
		std::cout << "Fehler beim laden der Datei. (./res/grafiken/tachoZeiger.png)" << std::endl;
	}
	this->tachoZeigerSprite.setTexture(this->tachoZeigerTextur);
	this->tachoZeigerSprite.setOrigin(this->tachoZeigerSprite.getGlobalBounds().getSize().x, this->tachoZeigerSprite.getGlobalBounds().getSize().y / 2);
	this->tachoZeigerSprite.setScale(2.2f, 2.2f);

	if (!this->lebensTexturen[0].loadFromFile("./res/grafiken/lebensstand_0_3.png")) std::cout << "Fehler beim laden der Datei. (./res/grafiken/lebensstand_0_3.png)" << std::endl;
	if (!this->lebensTexturen[1].loadFromFile("./res/grafiken/lebensstand_1_3.png")) std::cout << "Fehler beim laden der Datei. (./res/grafiken/lebensstand_1_3.png)" << std::endl;
	if (!this->lebensTexturen[2].loadFromFile("./res/grafiken/lebensstand_2_3.png")) std::cout << "Fehler beim laden der Datei. (./res/grafiken/lebensstand_2_3.png)" << std::endl;
	if (!this->lebensTexturen[3].loadFromFile("./res/grafiken/lebensstand_3_3.png")) std::cout << "Fehler beim laden der Datei. (./res/grafiken/lebensstand_3_3.png)" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->lebensSprites[i].setTexture(lebensTexturen[i]);
		this->lebensSprites[i].setScale(3.2f, 3.2f);
	}

	if (!this->PixeboyFont.loadFromFile("./res/schriftarten/Pixeboy-z8XGD.ttf"))						//	Läd die Schriftart aus der Datei "Pixeboy-z8XGD.ttf" (die Schriftart muss später im selben Verzeichniss sein wie die ausfürbare Datei)
	{
		std::cout << "Fehler beim laden der Schriftart! (./res/schriftarten/Pixeboy-z8XGD.ttf)" << std::endl;
	}
	if (!this->muenzeTextur.loadFromFile("./res/grafiken/muenze.png"))
	{
		std::cout << "Fehler beim laden der Textur! (./res/grafiken/muenze.png)" << std::endl;
	}
	this->muenzeSprite.setTexture(this->muenzeTextur);
	this->muenzeSprite.setScale(1.5f, 1.5f);
	this->muenzeSprite.setPosition(this->window->getView().getSize().x - this->muenzeSprite.getGlobalBounds().width, 25);

	this->geldText.setFont(this->PixeboyFont);
	this->geldText.setString("0");
	this->geldText.setFillColor(sf::Color::White);
	this->geldText.setOutlineColor(sf::Color::White);
	this->geldText.setCharacterSize(60);
	this->geldText.setLetterSpacing(1);
	this->geldText.setOrigin(0, this->geldText.getGlobalBounds().getSize().y * 1.5f);
	this->geldText.setPosition(this->muenzeSprite.getGlobalBounds().getPosition().x - this->geldText.getGlobalBounds().getSize().x - 5, this->muenzeSprite.getGlobalBounds().getPosition().y + this->muenzeSprite.getGlobalBounds().getSize().y / 2);
}

void Spieler::aktualisieren()
{
	this->rotation = this->sprite.getRotation();
	if (this->eingabeverwaltung->getGruppenStatus(0)) {
		this->geschwindigkeit += this->eigenschaften.beschlaeunigung;
	}
	if (this->eingabeverwaltung->getGruppenStatus(2)) {
		this->geschwindigkeit -= this->eigenschaften.beschlaeunigung;
	}
	if (this->eingabeverwaltung->getGruppenStatus(1)) {
		this->rotation -= 1 * geschwindigkeit / 2;
	}
	if (this->eingabeverwaltung->getGruppenStatus(3)) {
		this->rotation += 1 * geschwindigkeit / 2;
	}
	if (this->geschwindigkeit < 0) this->geschwindigkeit += this->eigenschaften.reibung;
	if (this->geschwindigkeit > 0) this->geschwindigkeit -= this->eigenschaften.reibung;
	if (this->geschwindigkeit > this->eigenschaften.maxGeschwindigkeit) this->geschwindigkeit = this->eigenschaften.maxGeschwindigkeit;
	if (this->geschwindigkeit < -this->eigenschaften.maxGeschwindigkeit) this->geschwindigkeit = -this->eigenschaften.maxGeschwindigkeit;
	this->sprite.setRotation(this->rotation);
	double rotationAlsWinkelmaß = this->sprite.getRotation() * 3.14159 / 180;
	double xGeschwindigkeit = sin(rotationAlsWinkelmaß) * geschwindigkeit;
	double yGeschwindigkeit = -1 * cos(rotationAlsWinkelmaß) * geschwindigkeit;
	this->bewegenUm(sf::Vector2f(xGeschwindigkeit, yGeschwindigkeit));

	if (this->unverwundbarNoch != 0) this->unverwundbarNoch -= 1;
	if (this->unverwundbarNoch == 0 && this->unverwundbar == true) this->unverwundbar = false;
}

void Spieler::anzeigen()
{
	float minSichtbarkeit = 77;
	float sichtbarkeit = 255 - (((float)this->unverwundbarNoch / (float)this->unverwundbarZeit) * (255 - (float)minSichtbarkeit) /*255*/);
	if (this->unverwundbar)this->sprite.setColor(sf::Color(255, 255, 255, sichtbarkeit /*(sichtbarkeit < minSichtbarkeit) ? minSichtbarkeit : sichtbarkeit*/));
	else this->sprite.setColor(sf::Color(255, 255, 255, 255));
	this->window->draw(this->sprite);
}

void Spieler::statusAnzeigen()
{
	this->tachoSprite.setPosition(this->window->getView().getCenter().x + (this->window->getView().getSize().x / 2 - this->tachoSprite.getGlobalBounds().width), this->window->getView().getCenter().y + (this->window->getView().getSize().y / 2 - this->tachoSprite.getGlobalBounds().height));
	this->window->draw(this->tachoSprite);
	float zeigerRotation = (abs(this->geschwindigkeit) / this->eigenschaften.maxGeschwindigkeit) * 180;
	this->tachoZeigerSprite.setRotation(zeigerRotation);
	this->tachoZeigerSprite.setPosition(this->tachoSprite.getGlobalBounds().getPosition().x + this->tachoSprite.getGlobalBounds().getSize().x / 2, this->tachoSprite.getGlobalBounds().getPosition().y + this->tachoSprite.getGlobalBounds().getSize().y / 2 + 15);
	this->window->draw(this->tachoZeigerSprite);
	this->lebensSprites[this->leben].setPosition(this->window->getView().getCenter().x - this->window->getView().getSize().x / 2, this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
	this->window->draw(this->lebensSprites[this->leben]);

	std::string string_tmp;
	int geld_tmp = this->geld;
	do {
		string_tmp.insert(string_tmp.begin(), (char)(geld_tmp % 10 + 48));
		geld_tmp /= 10;
	} while (geld_tmp != 0);
	this->geldText.setString(string_tmp);
	this->muenzeSprite.setPosition(this->window->getView().getSize().x - this->muenzeSprite.getGlobalBounds().width, this->window->getView().getCenter().y - this->window->getView().getSize().y / 2);
	this->geldText.setPosition(this->muenzeSprite.getGlobalBounds().getPosition().x - this->geldText.getGlobalBounds().getSize().x - 5, this->muenzeSprite.getGlobalBounds().getPosition().y + this->muenzeSprite.getGlobalBounds().getSize().y / 2);
	this->window->draw(this->muenzeSprite);
	this->window->draw(this->geldText);
}

void Spieler::setLeben(unsigned short leben)
{
	this->leben = leben;
}

void Spieler::setUnverwundbar(bool unverwundbar)
{
	this->unverwundbar = unverwundbar;
}

unsigned short Spieler::getLeben()
{
	return this->leben;
}

bool Spieler::getUnverwundbar()
{
	return this->unverwundbar;
}

void Spieler::schadenNehmen(unsigned short schaden)
{
	if (this->leben - schaden >= 0)this->leben -= schaden;
	this->unverwundbar = true;
	this->unverwundbarNoch = this->unverwundbarZeit;
}

void Spieler::setGeld(int geld)
{
	this->geld = geld;
}

int Spieler::getGeld()
{
	return this->geld;
}

void Spieler::hatMuenzeGesammelt()
{
	this->geld += 1;
}
