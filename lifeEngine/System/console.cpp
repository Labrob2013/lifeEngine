#include "console.h"
// ������� �������
/*
void le::Console::loadWidgets( tgui::Gui & gui )
{
	// ��������� ����
	auto theme = tgui::Theme::create("../scripts/gui/console.txt");

	// ����� ������
	//auto windowWidth = tgui::bindWidth(gui);
	//auto windowHeight = tgui::bindHeight(gui);
	auto windowWidth = 500;
	auto windowHeight = 100;

	// ���������
	tgui::EditBox::Ptr editBoxUsername = theme->load("EditBox");
	editBoxUsername->setSize(windowWidth * 2 / 3, windowHeight / 8);
	editBoxUsername->setPosition(windowWidth / 6, windowHeight / 6);
	editBoxUsername->setDefaultText("Username");
	gui.add(editBoxUsername, "Username");

	// ������
	tgui::Button::Ptr button = theme->load("Button");
	button->setSize(windowWidth / 2, windowHeight / 6);
	button->setPosition(windowWidth / 4, windowHeight * 7 / 10);
	button->setText("Login");
	gui.add(button);

	// Call the login function when the button is pressed
	// def: button->connect("pressed", login, editBoxUsername, editBoxPassword);
}
void le::Console::Update( tgui::Gui & gui )
{
	gui.draw();
}
le::Console::Console(System & system)
{
	gui = new tgui::Gui(system.GetWindow());
	tgui::Gui gui(system.GetWindow());
	try
	{
		// Load the widgets 
		loadWidgets(gui);
	}
	catch (const tgui::Exception& e)
	{
		std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
	}
	sf::Event event;
	while (system.GetWindow().pollEvent(event))
	{
		// ������ ������� ��� ���� ��������
		gui.handleEvent(event);
	}
	// Draw all created widgets
	gui.draw();
}
le::Console::~Console()
{
delete gui;
}
*/

// �� �������
/*
le::Console::Console(System & system)
{
	gui = new tgui::Gui(system.GetWindow());
	tgui::Gui gui(system.GetWindow());

	try
	{
		// Load the widgets
		loadWidgets(gui);
	}
	catch (const tgui::Exception& e)
	{
		std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
	}

	while (system.GetWindow().isOpen())
	{
		sf::Event event;
		while (system.GetWindow().pollEvent(event))
		{
			// ��� �������� ���� ������ ���������� �����������
			if (event.type == sf::Event::Closed)
				system.GetWindow().close();

			// ��� ��������� �������� ����, �������� ���
			else if (event.type == sf::Event::Resized)
			{
				system.GetWindow().setView(sf::View(sf::FloatRect(10, 0, event.size.width, event.size.height)));
				gui.setView(system.GetWindow().getView());
			}

			// ������ ������� ��� ���� ��������
			gui.handleEvent(event);
		}

		system.GetWindow().clear();

		// Draw all created widgets
		gui.draw();

		system.GetWindow().display();
	}
}*/