#include "requestmanager.h"

#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

Tool::RequestManager::RequestManager()
{
    manager = new QNetworkAccessManager;
}

Tool::RequestManager::~RequestManager() {
    delete manager;
}

QNetworkReply   *Tool::RequestManager::connectionRequest(const QString &email, const QString &password) {
    QUrl        url("http://62.210.237.116:8080/signin");

    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("email", email);
    params.addQueryItem("password", password);

    return manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
}

QNetworkReply   *Tool::RequestManager::registrationRequest(const QString &email, const QString &username, const QString &password) {
    QUrl        url("http://62.210.237.116:8080/signup");

    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("email", email);
    params.addQueryItem("username", username);
    params.addQueryItem("password", password);

    return manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
}
