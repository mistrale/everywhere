#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QBitmap>
#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>
#include <QComboBox>
#include <QProgressBar>
#include <QTabWidget>
#include <QStackedWidget>
#include <QScrollBar>

#include <iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.setCentralWidget(&w.widget);
    w.setFixedHeight(800);
;

    QWidget searchbar;

    w.layout->addWidget(&searchbar, 0, 0, 1, 2);

    searchbar.setStyleSheet("  background: rgb(3, 155, 229);");
    searchbar.setFixedSize(1435,40);

    QHBoxLayout layout2(&searchbar);


    layout2.addWidget(&w.menu);
    QPixmap pixmap1("C://Users/Aude/Documents/Everywhere/images/list.png" );
    QIcon menuIcon(pixmap1);
    w.menu.setIcon(menuIcon);
    w.menu.setIconSize(pixmap1.rect().size());
    w.menu.setFixedSize(pixmap1.rect().size());
    w.menu.setStyleSheet("border:none;");


    QWidget widgetbar;
    layout2.addWidget(&widgetbar);
    QHBoxLayout boxbar;
    widgetbar.setLayout(&boxbar);
    QWidget w2;
    boxbar.addWidget(&w2);
    QHBoxLayout b2;
    w2.setLayout(&b2);

    QLineEdit search("Rechercher ...");
    search.setFixedSize(QSize(500, 25));
    search.setStyleSheet("border:none; background: white;  color:#999;");
    QFont font ("Trocchi', serif", 10);
    search.setFont(font);

    QPushButton searchIcone;
    QPixmap pixmap5("C://Users/Aude/Documents/Everywhere/images/search.png");
    QIcon searchIcon(pixmap5);
    searchIcone.setIcon(searchIcon);
    searchIcone.setIconSize(pixmap5.rect().size());
    searchIcone.setFixedSize(pixmap5.rect().size() - QSize(2,2));
    searchIcone.setStyleSheet("background:white;border:none;");

    b2.addWidget(&search);
    b2.addWidget(&searchIcone);
    b2.setContentsMargins(0, 0, 0, 0);
    b2.setSpacing(10);

    QGraphicsDropShadowEffect* dropShadowEffect = new QGraphicsDropShadowEffect;
    dropShadowEffect->setBlurRadius(10);
    dropShadowEffect->setOffset(1);
    w2.setGraphicsEffect(dropShadowEffect);
    w2.setFixedSize(QSize(500, 26));
    w2.setStyleSheet("padding: 0px;");

    QComboBox service;
    service.addItem("All");
    service.addItem("YouTube");
    service.addItem("SoundCloud");
    b2.addWidget(&service);
    service.setStyleSheet("border:none; padding-left: 10px; ");
    service.setFixedSize(100, 30);

    QPushButton friends;
    layout2.addWidget(&friends);

    //
    // NOTIFICATION GAUCHE
    //
    QPixmap pixmap2("C://Users/Aude/Documents/Everywhere/images/contact.png");
    QIcon friendIcon(pixmap2);
    friends.setIcon(friendIcon);
    friends.setIconSize(pixmap2.rect().size());
    friends.setFixedSize(pixmap2.rect().size());
    friends.setStyleSheet("border:none;");

    QPushButton message;
    layout2.addWidget(&message);

    QPixmap pixmap4("C://Users/Aude/Documents/Everywhere/images/message.png" );
    QIcon messageIcon(pixmap4);
    message.setIcon(messageIcon);
    message.setIconSize(pixmap4.rect().size());
    message.setFixedSize(pixmap4.rect().size());
    message.setStyleSheet("border:none;");

    QPushButton notif;
    layout2.addWidget(&notif);

    QPixmap pixmap3("C://Users/Aude/Documents/Everywhere/images/notif.png" );
    QIcon notifIcon(pixmap3);
    notif.setIcon(notifIcon);
    notif.setIconSize(pixmap3.rect().size());
    notif.setFixedSize(pixmap3.rect().size());
    notif.setStyleSheet("border:none;");

    layout2.setContentsMargins(20, 0, 20, 0);
    layout2.setSpacing(20);

    //
    // LIST FONCTIONNALITES
    //
    w.layout->addWidget(&w.menuList, 1, 0);
    w.menuList.setStyleSheet("background: rgb(0, 131, 143); ");
    QVBoxLayout menuBox;
    w.menuList.setLayout(&menuBox);
    menuBox.setContentsMargins(0,0,0,0);
    menuBox.setAlignment(Qt::AlignTop);
    menuBox.setSpacing(0);

    QGraphicsDropShadowEffect* dropShadowEffect2 = new QGraphicsDropShadowEffect;
    dropShadowEffect2->setBlurRadius(10);
    dropShadowEffect2->setOffset(1);
    w.menuList.setGraphicsEffect(dropShadowEffect2);

    QPushButton deconnexion("Deconnexion");
    deconnexion.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    deconnexion.setStyleSheet("QPushButton {border:1px solid white; background: rgb(100,203,253);;}"
                            "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    QPushButton advanced("Recherche avancée");
    advanced.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    advanced.setStyleSheet("QPushButton {border:1px solid white; background:  rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    QPushButton shares("Mes partages");
    shares.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    shares.setStyleSheet("QPushButton {border:1px solid white;background: rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    QPushButton bibli("Bibliothèque");
    bibli.setStyleSheet("QPushButton {border:1px solid white; background:  rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    bibli.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    QPushButton actu("Actualités");
    actu.setStyleSheet("QPushButton {border:1px solid white; background:  rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    actu.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    QPushButton profil("Profil");
    profil.setStyleSheet("QPushButton {border:1px solid white;background:  rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    profil.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    QPushButton stream("Stream");
    stream.setStyleSheet("QPushButton {border:1px solid white;background:  rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    stream.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    QPushButton devices("Devices");
    devices.setStyleSheet("QPushButton {border:1px solid white;background:  rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    devices.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    QPushButton services("Services");
    services.setStyleSheet("QPushButton {border:1px solid white; background: rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border: 1px solid white;}");
    services.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    QPushButton dl("Mes téléchargements");
    dl.setStyleSheet("QPushButton {border:1px solid white;background:  rgb(100,203,253);}"
                     "QPushButton:hover { background: rgb(3, 155, 229); border:  white;}");
    dl.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    std::cout << dl.width()
              << dl.height() << std::endl;

    menuBox.addWidget(&advanced);
    menuBox.addWidget(&actu);
    menuBox.addWidget(&shares);
    menuBox.addWidget(&bibli);
    menuBox.addWidget(&dl);
    menuBox.addWidget(&devices);
    menuBox.addWidget(&stream);
    menuBox.addWidget(&services);
    menuBox.addWidget(&profil);
    menuBox.addWidget(&deconnexion);

    //
    // CONTENT
    //
    QWidget content;
    w.layout->addWidget(&content, 1, 1);
    content.setStyleSheet("background : url(C://Users/Aude/Documents/Everywhere/images/background.png);");

    QGridLayout gridContent;
    content.setLayout(&gridContent);
    gridContent.setContentsMargins(15,15,15,15);
    QWidget player;
    gridContent.addWidget(&player, 0,0);

    QWidget nextSong;
    gridContent.addWidget(&nextSong, 0, 1, 2, 1);

    QTabWidget infos;
    gridContent.addWidget(&infos, 1, 0, Qt::AlignBottom);


    //
    // PLAYER
    //
    player.setFixedSize(740, 400);
    player.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    QGraphicsDropShadowEffect* shadowPlayer = new QGraphicsDropShadowEffect;
    shadowPlayer->setBlurRadius(8);
    shadowPlayer->setOffset(10);
    player.setGraphicsEffect(shadowPlayer);
    QVBoxLayout playerLayout;
    player.setLayout(&playerLayout);
    playerLayout.setMargin(0);

    QWidget image;
    playerLayout.addWidget(&image);
    image.setStyleSheet("background: url(C://Users/Aude/Documents/Everywhere/images/video.png);"
                        "border: 1px solid white;");
    image.setFixedHeight(360);

    QProgressBar bar;
    playerLayout.addWidget(&bar);
    bar.setFixedSize(740, 10);
    bar.setStyleSheet("margin: 2px; margin-left: 7px; margin-right: 7px;");


    //
    // CONTROLE
    //
    QWidget controle;
    QHBoxLayout controleLayout;
    playerLayout.addWidget(&controle);
    controle.setLayout(&controleLayout);
    controle.setStyleSheet(" background: rgb(3, 155, 229); border: 1px solid white;");

    QPushButton playBackButton;
    controleLayout.addWidget(&playBackButton);

    QPixmap pixmapPlayBack("C://Users/Aude/Documents/Everywhere/images/back.png" );
    QIcon playBack(pixmapPlayBack);
    playBackButton.setIcon(playBack);
    playBackButton.setIconSize(pixmapPlayBack.rect().size());
    playBackButton.setFixedSize(pixmapPlayBack.rect().size());
    playBackButton.setStyleSheet("border:none;");

    QPushButton playButton;
    controleLayout.addWidget(&playButton);

    QPixmap pixmapPlay("C://Users/Aude/Documents/Everywhere/images/play.png" );
    QIcon play(pixmapPlay);
    playButton.setIcon(play);
    playButton.setIconSize(pixmapPlay.rect().size());
    playButton.setFixedSize(pixmapPlay.rect().size());
    playButton.setStyleSheet("border:none;");

    QPushButton playNextButton;
    controleLayout.addWidget(&playNextButton);

    QPixmap pixmapPlayNext("C://Users/Aude/Documents/Everywhere/images/next.png" );
    QIcon playNext(pixmapPlayNext);
    playNextButton.setIcon(playNext);
    playNextButton.setIconSize(pixmapPlayNext.rect().size());
    playNextButton.setFixedSize(pixmapPlayNext.rect().size());
    playNextButton.setStyleSheet("border:none;");

    QPushButton offButton;
    controleLayout.addWidget(&offButton);

    QPixmap pixmapOff("C://Users/Aude/Documents/Everywhere/images/volume-off.png" );
    QIcon off(pixmapOff);
    offButton.setIcon(off);
    offButton.setIconSize(pixmapOff.rect().size());
    offButton.setFixedSize(pixmapOff.rect().size());
    offButton.setStyleSheet("border:none;margin-left: 20px;");

    QPushButton settingsButton;
    controleLayout.addWidget(&settingsButton);

    QPixmap pixmapSettings("C://Users/Aude/Documents/Everywhere/images/settings.png" );
    QIcon settings(pixmapSettings);
    settingsButton.setIcon(settings);
    settingsButton.setIconSize(pixmapSettings.rect().size());
    settingsButton.setFixedSize(pixmapSettings.rect().size());
    settingsButton.setStyleSheet("border:none;");

    QPushButton fullScreenButton;
    controleLayout.addWidget(&fullScreenButton);

    QPixmap pixmapFullScreen("C://Users/Aude/Documents/Everywhere/images/fullscreen.png" );
    QIcon fullScreen(pixmapFullScreen);
    fullScreenButton.setIcon(fullScreen);
    fullScreenButton.setIconSize(pixmapFullScreen.rect().size());
    fullScreenButton.setFixedSize(pixmapFullScreen.rect().size());
    fullScreenButton.setStyleSheet("border:none;");


    //
    // NEXT SONG
    //
    nextSong.setStyleSheet("background: rgba(255,255,255, 0.3);");
    nextSong.setFixedSize(400, 675);
    QGraphicsDropShadowEffect* nextSongShadow = new QGraphicsDropShadowEffect;
    nextSongShadow->setBlurRadius(8);
    nextSongShadow->setOffset(10);
    nextSong.setGraphicsEffect(nextSongShadow);

    //
    //
    //INFO	
    infos.setStyleSheet("QTabBar::tab{height:40px; width:368px; color:white;font: 9pt; background: rgb(3, 155, 229);"
                        "border: 1px solid white;}"
                        "QTabBar::tab:selected, QTabBar::tab:hover {"
                        "background:  rgb(100,203,253);}");
    infos.tabBar()->setExpanding(true);
    infos.setFixedSize(740, 250);
    QGraphicsDropShadowEffect* infosShadow = new QGraphicsDropShadowEffect;
    infosShadow->setBlurRadius(8);
    infosShadow->setOffset(10);
    infos.setGraphicsEffect(infosShadow);

    QWidget informations;
    infos.addTab(&informations, "Informations");

    QGridLayout infosLayout;
    informations.setLayout(&infosLayout);

    // TAB INFORMATIONS
    QLabel      label("Natural Animal - Who You Are");
    label.setStyleSheet("color: white; font-size: 15px; font-weight: bold;");
    label.setFixedHeight(30);
    infosLayout.addWidget(&label, 0, 0, 1, 3, Qt::AlignLeft);

    QPushButton artistButton;
    QPixmap pixmapLabel("C://Users/Aude/Documents/Everywhere/images/TGV.png");
    QIcon artisteIcon(pixmapLabel);
    artistButton.setIcon(artisteIcon);
    artistButton.setIconSize(pixmapLabel.rect().size());
    artistButton.setFixedSize(pixmapLabel.rect().size());
    artistButton.setStyleSheet("border: none; ");
    infosLayout.addWidget(&artistButton, 1, 0, 2, 1, Qt::AlignLeft);

    QLabel      label2("TGV - The Guide Vibe");
    label2.setStyleSheet("color: white; font-size: 10px; background: transparent");
    infosLayout.addWidget(&label2, 1, 1, 1, 3, Qt::AlignLeft);

    QPushButton addButton;
    QPixmap pixmapAdd("C://Users/Aude/Documents/Everywhere/images/add.png");
    QIcon addIcon(pixmapAdd);
    addButton.setIcon(addIcon);
    addButton.setIconSize(pixmapAdd.rect().size());
    addButton.setFixedSize(pixmapAdd.rect().size());
    addButton.setStyleSheet("border:none;");
    infosLayout.addWidget(&addButton, 2, 1, 1, 1, Qt::AlignLeft);

    QPushButton shareButton;
    QPixmap pixmapShare("C://Users/Aude/Documents/Everywhere/images/share.png");
    QIcon shareIcon(pixmapShare);
    shareButton.setIcon(shareIcon);
    shareButton.setIconSize(pixmapShare.rect().size());
    shareButton.setFixedSize(pixmapShare.rect().size());
    shareButton.setStyleSheet("border:none;");
    infosLayout.addWidget(&shareButton, 2, 2, 1, 1, Qt::AlignLeft);

    QPushButton repostButton;
    QPixmap pixmapRepost("C://Users/Aude/Documents/Everywhere/images/repost.png");
    QIcon repostIcon(pixmapRepost);
    repostButton.setIcon(repostIcon);
    repostButton.setIconSize(pixmapRepost.rect().size());
    repostButton.setFixedSize(pixmapRepost.rect().size());
    repostButton.setStyleSheet("border:none;");
    infosLayout.addWidget(&repostButton, 2, 3, 1, 1, Qt::AlignLeft);

    QPushButton subscribeButton;
    QPixmap pixmapsubscribe("C://Users/Aude/Documents/Everywhere/images/subscribe.png");
    QIcon subscribeIcon(pixmapsubscribe);
    subscribeButton.setIcon(subscribeIcon);
    subscribeButton.setIconSize(pixmapsubscribe.rect().size());
    subscribeButton.setFixedSize(pixmapsubscribe.rect().size());
    subscribeButton.setStyleSheet("border:none;");
    infosLayout.addWidget(&subscribeButton, 2, 4, 1, 1, Qt::AlignLeft);

    QScrollBar scrollBar;


    infosLayout.addWidget(&scrollBar, 0, 4, 4, 1, Qt::AlignRight);

    QWidget commentaires;
    infos.addTab(&commentaires, "Commentaires");

    //
    // MAIN GRID BOX
    //
    w.layout->setMargin(0);
    w.layout->setSpacing(1);


    w.show();

    return a.exec();
}
