#include <curl/curl.h>
#include <string.h>
#include <stdio.h>

void send_email(const char* from_email, const char* to_email, const char* subject, const char* body, const char* attachment) {
    CURL* curl;
    CURLcode res = CURLE_OK;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        struct curl_slist* recipients = NULL;
        curl_easy_setopt(curl, CURLOPT_USERNAME, from_email);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password");
        curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.mail.yahoo.com:465");
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from_email);

        recipients = curl_slist_append(recipients, to_email);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from_email);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);

        struct curl_httppost* formpost = NULL;
        struct curl_httppost* lastptr = NULL;
        if (attachment != NULL) {
            curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "file", CURLFORM_FILE, attachment, CURLFORM_END);
        }

        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);

        char recipients_string[1024];
        memset(recipients_string, 0, sizeof(recipients_string));
        snprintf(recipients_string, sizeof(recipients_string), "To: %s", to_email);

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, from_email);
        headers = curl_slist_append(headers, recipients_string);
        headers = curl_slist_append(headers, "Content-Type: text/plain");

        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, headers);

        const char* message[] = {body};
        curl_easy_setopt(curl, CURLOPT_READDATA, message);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        res = curl_easy_perform(curl);

        curl_slist_free_all(recipients);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        curl_formfree(formpost);
    }

    curl_global_cleanup();
}

int main(int argc, char **argv)
{
	if (argc != 6)
	{
		printf("./send_email from@example.com, to@example.com, Subject, Body, attachment.txt\n");
		return -(1);
	}
	printf("From email = %s\nTo email: %s\nSubject: %s\n\nMessage:\n%s\n\nAttachement: %s\n", av[1], av[2], av[3], av[4], av[5]);
	send_email(argv[1], argv[2], argv[3], argv[4], argv[5]);
	printf("Email successfully sent\n");
	return (0);
}
