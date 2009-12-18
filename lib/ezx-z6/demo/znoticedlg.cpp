#include <ZApplication.h>
#include <ZNoticeDlg.h>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static void usage(char * prog)
{
    fprintf(stderr, "Usage: %s [ -H HEADER_TEXT ] [ -M SUBHEADER_TEXT ] [ -t #TIMEOUT ]"
	    "[ -S notice | exclamation | nothing | #VAL ] MESSAGE_TEXT ...\n",
	    prog);
    exit(-1);
}

int main(int argc, char **argv)
{
	ZApplication* a = new ZApplication(argc, argv);

	QString head("Header");
	char * subhead = NULL;
	QString msg;
	ZNoticeDlg::Type type = ZNoticeDlg::nothing;
	int timeout = 0;

	int ch;

	while ((ch = getopt(argc, argv, "H:t:S:M:")) != EOF) {
	    switch (ch) {
	    case 'H':
		head = QString::fromUtf8(optarg);
		break;
	    case 'M':
		subhead = optarg;
		break;
	    case 't':
		timeout = atoi(optarg);
		break;
	    case 'S':
		if (strcmp(optarg, "notice") == 0)
		    type = ZNoticeDlg::notice;
		else if (strcmp(optarg, "exclamation") == 0)
		    type = ZNoticeDlg::exclamation;
		else if (strcmp(optarg, "nothing") == 0)
		    type = ZNoticeDlg::exclamation;
		else
		    type = (ZNoticeDlg::Type)atoi(optarg);
		break;
	    default:
		usage(argv[0]);
	    }
	}

	argc -= optind;
	argv += optind;

	msg = QString("");

	while (argc > 0) {
	    msg += QString::fromUtf8(argv[0]);
	    argc--; argv++;
	    if (argc)
		msg += QString("\n");
	}

	ZNoticeDlg *dlg = new ZNoticeDlg(type,
					 timeout*1000,
					 subhead ? QString::fromUtf8(subhead) : NULL,
					 msg, NULL,
					 "ZNoticeDlg", true, 0);

	dlg->setTitle(head);

   	a->setMainWidget(dlg);
    	dlg->show();
   	a->exec();

	int result = dlg->result();

	printf("Result = %d\n", result);

	return result;
}
