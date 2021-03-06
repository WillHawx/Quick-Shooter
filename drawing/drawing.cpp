#include <SFML\Graphics.hpp>
#include <iostream>
#include "UIManager.h"
#include <time.h>  
#include <string>
#include <sstream>
#include <ctime> 
using namespace std;
using namespace sf;

time_t current_time;
int powerup = 7;
int diff = 1;
int col = 1;
int score = 0;
int hp = 3;
int r = 255;
int b = 0;
int g = 0;


//CLASS ENEMY------------------------------------------------------------------------------------------
class enemy
{
protected:
	
	int timer;
	int counter;
	Vector2f size;
	Vector2f sizeeye;
	Vector2f sizemouth;
	Vector2f epos;
	Vector2f eyelpos;
	Vector2f eyerpos;
	Vector2f mouthpos;
	int color;
	RectangleShape  rect;
	CircleShape  eyel;
	CircleShape  eyer;
	CircleShape  mouth;
	time_t timex;

	
	

public:
	int delay;
	enemy(int c=1)
	{
		delay = 2000;
		size.x = 100;
		size.y = 100;
		
		timer = 4000;
		srand(time(NULL));
		epos.x = rand() % 700 + 0;
		epos.y = rand() % 500 + 0;
		eyelpos.x = epos.x + 20;
		eyelpos.y = epos.y + 30;
		eyerpos.x = epos.x + 60;
		eyerpos.y = epos.y + 30;
		mouthpos.x = epos.x + 45;
		mouthpos.y = epos.y + 50;


		rect.setSize(size);
		eyel.setRadius(10);
		eyel.setPointCount(20);
		eyer.setRadius(10);
		eyer.setPointCount(20);
		mouth.setRadius(30);
		mouth.setPointCount(3);
		rect.setPosition(epos);
		eyel.setPosition(eyelpos);
		eyer.setPosition(eyerpos);
		mouth.setPosition(mouthpos);

		color = c;
		
		switch (color)
		{
		case 1: //red
			rect.setFillColor(Color(255, 0, 0, 255));
			break;


		case 2: //green
			rect.setFillColor(Color(0, 255, 0, 255));
			break;

		case 3: //blue
			rect.setFillColor(Color(0, 0, 255, 255));
			break;
		case 4:
			rect.setFillColor(Color(137, 65, 124, 255));
			break;
		}
		eyel.setFillColor(Color(240, 230, 0, 255));
		eyer.setFillColor(Color(240, 230, 0, 255));
		mouth.setFillColor(Color(240, 230, 0, 255));
		
	}
	int getcolor()
	{
		return color;
	
	}
	void setcolor(int c)
	{
		color = c;
	
	}

	
	void respawn()
	{
		
		epos.x = rand() % 700 + 0;

		epos.y = rand() % 500 + 0;
		rect.setPosition(epos);

		eyelpos.x = epos.x + 20;
		eyelpos.y = epos.y + 30;
		eyerpos.x = epos.x + 60;
		eyerpos.y = epos.y + 30;
		mouthpos.x = epos.x + 22.5;
		mouthpos.y = epos.y + 50;


		
		rect.setPosition(epos);
		eyel.setPosition(eyelpos);
		eyer.setPosition(eyerpos);
		mouth.setPosition(mouthpos);
		
		timex = time(NULL);
		
		
		switch (diff)
		{
		case 1:
			timer = 4000;
				break;
		case 2:
			timer = 2000;
				break;
		case 3:
			timer = 1000;
			break;
		case 4:
			timer = 500;
			break;
		default:
			timer = 4000;
			break;
		}
		
		
	
	}

	

	int gettime()
	{
		int temp = timex;
		return temp;
	
	}
	int getposx()
	{
		return epos.x;

	}

	int getposy()
	{
		return epos.y;

	}

	int check(Vector2i cpos, int col)
	{
		if ((cpos.x > epos.x && cpos.x < epos.x + 100) && (cpos.y > epos.y && cpos.y < epos.y + 100) && (color == col))
			return 1;
		else return 0;
		

	
	
	}

	
	void click()
	{
		timer --;
	}
	int gettimer()
	{
		return timer;
	}
	RectangleShape getshape()
	{return rect; }

	CircleShape geteyel()
	{
		return eyel;
	}
	CircleShape geteyer()
	{
		return eyer;
	}
	CircleShape getmouth()
	{
		return mouth;
	}
};


//class gift.........................................................................................
class gift :public enemy
{
	int swch = 0;

	time_t lifetime;
	time_t delaytime;
	

public:
	gift(int c=1)
	{
		
		lifetime = time(NULL);
		delaytime = time(NULL);
		srand(time(NULL));
		eyelpos.x =800;
		eyelpos.y =600;
		


		
		eyel.setRadius(10);
		eyel.setPointCount(20);
		
		eyel.setPosition(eyelpos);
		

		color = c;

		switch (color)
		{
		case 1: //red hp
			eyel.setFillColor(Color(255, 0, 0, 255));
			break;


		case 2: //green power
			eyel.setFillColor(Color(0, 255, 0, 255));
			break;

		case 3: //blue score
			eyel.setFillColor(Color(0, 0, 255, 255));
			break;
		
		}
		

	

	
	
	}

	int getswch()
	{
		return swch;
	}

	void respawn()
	{

		eyelpos.x = rand() % 700 + 0;

		eyelpos.y = rand() % 500 + 0;
		eyel.setPosition(eyelpos);
		cout << "gift respanw";

		
		//delaytime = time(NULL);
		lifetime = time(NULL);
		swch = 1;

	}
	
	void resetTime()
	{
		timex = time(NULL);
	
	}
	int check(Vector2i cpos ,int col)
	{
		cout << "checking gift hit";
		
		if ((cpos.x > (eyelpos.x - 30) && cpos.x < (eyelpos.x + 30)) && (cpos.y > (eyelpos.y - 30) && cpos.y < (eyelpos.y + 30)) && (color == col))
		{
			cout << "ahit!!!";
			return 1;
		}
		else return 0;
	
	}

	void despawn()
	{
		eyelpos.x = 800;
		eyelpos.y + 600;
		eyel.setPosition(eyelpos);
		delaytime = time(NULL);
		//lifetime = time(NULL);

		swch = 0;


	}

	int getdelaytime()
	{
		return delaytime;
	
	}

	int getlifetime()
	{
		return lifetime;

	}



};



//void cenemey( int c)
//{
//	
//	enemy *e = new enemy(c);
//
//}
//void denemy(enemy *e)
//{
//	delete e;
//
//}

void checkdiff()
{
	if (score >999)diff =4;
	else if (score > 499)diff = 3;
	
	else if (score > 119)diff = 2;

}
void recolor()
{
	col = rand() % 3+ 1;
	if (col == 2)
	{
		r = 0;
		g = 255;
		b = 0;
	}

	else if (col == 3)
	{
		g = 0;
		b = 255;
		r = 0;
	}

	else if (col == 1)
	{
		b = 0;
		r = 255;
		g = 0;
	}

	

}
void update()
{
	system("CLS");
	cout << "score:" << score << "      Health:" << hp << "\n" << "diff:" << diff << "      power:" << powerup << "\n";
	//sf::String Text;
	//Text.SetText("Hello");
	
	

	//sf::String Text("Hello", MyFont, 50);

	// Or, if you want to do it after the construction :

	//sf::String t;
	

	
}


Text drawText()
{
	Font f;
	if (!f.loadFromFile("Walkway_Black.ttf"))
	{
		// Error...		
	}
	Text t("  ", f, 50);
	ostringstream v;
	std::string var;
	t.setPosition(0, 0);
	t.setCharacterSize(20);
	t.setFillColor(Color(0, 0, 0, 255));
	v << "score:" << score << "      Health:" << hp << "\n" << "diff:" << diff << "      power:" << powerup << "\n";
	var = v.str();
	t.setString(var);
	return t;

}

int targetCheck(enemy *ered, enemy *egreen, enemy *eblue, Vector2i cpos)
{

	if (ered->check(cpos, col) == 1)
	{
		ered->respawn();
		score += 20;
		powerup++;
		return 1;
	}

	else if (egreen->check(cpos, col) == 1)
	{
		egreen->respawn();
		score += 20;
		powerup++;
		return 1;
	}

	else if (eblue->check(cpos, col) == 1)
	{
		eblue->respawn();
		score += 20;
		powerup++;
		return 1;
	}

	else
	{

		
		return 0;
		


	}


}

int targetCheck2(gift *ered, gift *egreen, gift *eblue, Vector2i cpos)
{

	if (ered->check(cpos, col) == 1)
	{
		ered->despawn();
		score += 20;
		hp++;
		cout << "((you hit red gift))";
		return 1;
	}

	else if (egreen->check(cpos, col) == 1)
	{
		egreen->despawn();
		score += 20;
		powerup += 3;
		return 1;

	}

	else if (eblue->check(cpos, col) == 1)
	{
		eblue->despawn();
		score += 20;
		score += 100;
		return 1;
	}

	else
	{

		
		return 0;



	}


}

void changeLoc(enemy *ered, enemy *egreen, enemy *eblue)
{

	checkdiff();
	int countdown;
	switch (diff)
	{
	case 1:
		countdown = 3;
		break;
	case 2:
		countdown = 2;
		break;
	case 3:
		countdown = 1;
		break;
	case 4:
		countdown = 0.3;
		break;

	}


	if (time(NULL) - ered->gettime() > countdown)
	{
		ered->respawn(); powerup--; 
	}
	if (time(NULL) - egreen->gettime() > countdown)
	{
		egreen->respawn(); powerup--; 
	}

	if (time(NULL) - eblue->gettime() > countdown)
	{
		eblue->respawn();
		powerup--;
		
	}
	if (powerup < 1)
	{
		powerup = 5;
		hp--;
		
	}
}


void updateBk(RectangleShape *bk)
{
	switch (diff)
	{
	case 1:
		bk->setFillColor(Color(184, 231, 244, 255));
		break;
	case 2:
		bk->setFillColor(Color(123, 179, 131, 255));
		break;

	case 3:
		bk->setFillColor(Color(200, 191, 131, 255));
		break;

	case 4:
		bk->setFillColor(Color(225, 181, 131, 255));
		break;


	}
}

//main--------------------------------------------------------------------------------------------------------------
void main()
{
	

	//initialization 

	RenderWindow w; //window
	w.create(VideoMode(800, 600), "drawer");

	Event e; //event

	auto  c = CircleShape(10, 30); //crusor
	Vector2i cpos;
	c.setOrigin(10, 10);
	c.setFillColor(Color(r, g, b, 255));
	enemy ered(1); //enemies
	enemy egreen(2);
	enemy eblue(3);

	gift ghp(1);
	gift gpower(2);
	gift gscore(3);


	RectangleShape bk; //background
	Vector2f bkpos(0, 0);
	Vector2f bksize(800, 600);
	bk.setPosition(bkpos);
	bk.setSize(bksize);
	bk.setFillColor(Color(184, 231, 244, 255));


	Font f;
	if (!f.loadFromFile("Walkway_Black.ttf"))
	{
		// Error...		
	}
	Text t("  ", f, 50);
	Text t1("  ", f, 50);
	ostringstream v;
	std::string var;
	t.setPosition(0, 0);
	t.setCharacterSize(20);
	t.setFillColor(Color(0, 0, 0, 255));








	//spawning enemies for the forst time before entering loop
	ered.respawn();
	egreen.respawn();
	eblue.respawn();
	//update();



	while (w.isOpen())

	{

		w.clear();
		v.str("");
		v.clear();
		w.pollEvent(e);
		cpos = Mouse::getPosition(w);

		switch (e.type)
		{

		case Event::EventType::MouseMoved:
		{
			c.setPosition(cpos.x, cpos.y);
			break;

		}

		case Event::EventType::MouseButtonPressed:
		{

			int a1, a2;
			a1 = targetCheck(&ered, &egreen, &eblue, cpos); 
			a2 = targetCheck2(&ghp, &gpower, &gscore, cpos);
				if (a1+a2 == 0)
				hp--;


			recolor();
			c.setFillColor(Color(r, g, b, 255));


			sleep(seconds(0.1));
			break;
		}
		}



		changeLoc(&ered, &egreen, &eblue);
		if (time(NULL) - ghp.getlifetime() > (rand() % 5 + 3) && ghp.getswch() == 1 )//5 is the time th gift will stay on the screen
			ghp.despawn();
		if (time(NULL) - gscore.getlifetime() > (rand() % 5 + 3) && gscore.getswch() == 1)//5 is the time th gift will stay on the screen
			gscore.despawn();
		if (time(NULL) - gpower.getlifetime() > (rand() % 5 + 3) && gpower.getswch() == 1)//5 is the time th gift will stay on the screen
			gpower.despawn();


		if (time(NULL) - ghp.getdelaytime() > (rand() % 10 + 5) && ghp.getswch() == 0)//5 is the time th gift will stay on the screen
			ghp.respawn();
		if (time(NULL) - gscore.getdelaytime() > (rand() % 10 + 5) && gscore.getswch() == 0)//5 is the time th gift will stay on the screen
			gscore.respawn();
		if (time(NULL) - gpower.getdelaytime() > (rand() % 10 + 5) && gpower.getswch() == 0)//5 is the time th gift will stay on the screen
			gpower.respawn();

		

		

		
		updateBk(&bk);


		v << "Score:" << score << "      Health:" << hp << "\n" << "Difficulty:" << diff << "    Power:" << powerup << "\n";
		var = v.str();
		t.setString(var);

		//drawing shapes
		w.draw(bk);

		w.draw(ered.getshape());
		w.draw(ered.geteyel());
		w.draw(ered.geteyer());
		w.draw(ered.getmouth());

		w.draw(egreen.getshape());
		w.draw(egreen.geteyel());
		w.draw(egreen.geteyer());
		w.draw(egreen.getmouth());

		w.draw(eblue.getshape());
		w.draw(eblue.geteyel());
		w.draw(eblue.geteyer());
		w.draw(eblue.getmouth());

		w.draw(ghp.geteyel());
		w.draw(gpower.geteyel());
		w.draw(gscore.geteyel());

		w.draw(c);

		w.draw(t);

		w.display();
		update();


		if (hp < 1)
		{
			t1.setPosition(100, 200);
			ostringstream v2;
			v2 << "GAMEOVER!!\nYour Score:" << score;
			//var.clear();
			var = v2.str();
			t1.setString(var);
			t1.setCharacterSize(100);
			t1.setFillColor(Color(255, 30, 50, 255));
			w.draw(t);
			w.draw(t1);
			w.display();
			sleep(seconds(4));
			//reset game

			score = 0;
			hp = 3;
			diff = 1;
			powerup = 5;

			ered.respawn();
			egreen.respawn();
			eblue.respawn();

			ghp.despawn();
			gpower.despawn();
			gscore.despawn();




			//w.close();
			//break;
		}





	}

	
	
}
	
	
