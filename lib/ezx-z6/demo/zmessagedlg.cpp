#include <ZApplication.h>
#include <ZMessageDlg.h>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static void usage(char * prog)
{
    fprintf(stderr, "Usage: %s [ -H HEADER_TEXT ] [ -t #TIMEOUT ]"
	            "[ -S ok_cancel | yes_no | ok | #VAL ] MESSAGE_TEXT...\n",
	    prog);
    exit(-1);
}

int main(int argc, char **argv)
{
	ZApplication* a = new ZApplication(argc, argv);

	QString head("Header");
	QString msg;
	ZMessageDlg::MessageDlgType type = ZMessageDlg::ok_cancel;
	int timeout = 0;

	int ch;
	while ((ch = getopt(argc, argv, "H:t:S:")) != EOF) {
	    switch (ch) {
	    case 'H':
		head = QString::fromUtf8(optarg);
		break;
	    case 't':
		timeout = atoi(optarg);
		break;
	    case 'S':
		if (strcmp(optarg, "ok_cancel") == 0)
		    type = ZMessageDlg::ok_cancel;
		else if (strcmp(optarg, "yes_no") == 0)
		    type = ZMessageDlg::yes_no;
		else if (strcmp(optarg, "ok") == 0)
		    type = ZMessageDlg::just_ok;
		else
		    type = (ZMessageDlg::MessageDlgType)atoi(optarg);
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

	ZMessageDlg* dlg = new ZMessageDlg(head, msg, type,
					   timeout*1000, NULL, "ZMessageDlg", true, 0);

   	a->setMainWidget(dlg);
    	dlg->show();
   	a->exec();

	int result = dlg->result();

	printf("Result = %d\n", result);

	return result;
}
