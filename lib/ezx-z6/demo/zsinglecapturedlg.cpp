#include <ZApplication.h>
#include <ZSingleCaptureDlg.h>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static void usage(char * prog)
{
    fprintf(stderr, "Usage: %s [ -H HEADER_TEXT ] "
	            "[ -S normal | secret | #VAL ] MESSAGE_TEXT...\n",
	    prog);
    exit(-1);
}

int main( int argc, char **argv )
{
	ZApplication* a = new ZApplication( argc, argv );
	QString head("Header");
	QString msg;
	ZSingleCaptureDlg::CaptureDlgType type = ZSingleCaptureDlg::normal;

	int ch;
	while ((ch = getopt(argc, argv, "H:S:")) != EOF) {
	    switch (ch) {
	    case 'H':
		head = QString::fromUtf8(optarg);
		break;
	    case 'S':
		if (strcmp(optarg, "normal") == 0)
		    type = ZSingleCaptureDlg::normal;
		else if (strcmp(optarg, "secret") == 0)
		    type = ZSingleCaptureDlg::secret;
		else
		    type = (ZSingleCaptureDlg::CaptureDlgType)atoi(optarg);
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

	ZSingleCaptureDlg* dlg = new ZSingleCaptureDlg(head, msg, type,
						       NULL, "ZSingleCaptureDlg",
						       true, 0, 0);

   	a->setMainWidget( dlg );
    	dlg->show();
   	a->exec();

	int result = dlg->result();
	if (result != 0 ) {
		printf(dlg->getResultText().utf8());
		result = 1;
	}

	return result;
}
