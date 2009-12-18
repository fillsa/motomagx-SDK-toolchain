#include <ZApplication.h>
#include <ZSingleSelectDlg.h>
#include <ZListBox.h>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static void usage(char * prog)
{
    fprintf(stderr, "Usage: %s [ -H HEADER_TEXT ] [ -t #TIMEOUT ] "
	            "ITEM1_TEXT ITEM2_TEXT ...\n",
	    prog);
    exit(-1);
}

int main(int argc, char **argv)
{
	ZApplication* a = new ZApplication(argc, argv);
	QString head("Header");
	QString msg("What?");
	QStringList list;
	int checked = -1;
	int timeout = 0;

	int ch;
	while ((ch = getopt(argc, argv, "H:M:S:t:")) != EOF) {
	    switch (ch) {
	    case 'H':
		head = QString::fromUtf8(optarg);
		break;
	    case 'M':
		msg = QString::fromUtf8(optarg);
		break;
	    case 't':
		timeout = atoi(optarg);
		break;
	    default:
		usage(argv[0]);
	    }
	}

	argc -= optind;
	argv += optind;

	int count = 0;

	while (argc > 0) {
	    char * str = argv[0];
	    if (str[0] == '+') {
		str++;
		checked = count;
	    }
	    list += QString::fromUtf8(str);
	    argc--; argv++; count++;
	}

	ZSingleSelectDlg* dlg = new ZSingleSelectDlg(head, msg, NULL,
						   "ZSingleSelectDlg", true,
						   0, 0);

	dlg->addItemsList(list);

	ZListBox* listbox = dlg->getListBox();
	if (checked >= 0)
	    listbox->checkItem(checked, true);

	if (timeout)
	    dlg->setAutoDismissTime(timeout*1000);

   	a->setMainWidget( dlg );
    	dlg->show();
   	a->exec();

	int result = dlg->result();
	if (result != 1) {
	    result = 0;
	} else {
		result = dlg->getCheckedItemIndex();
		printf("Index: %d\n", result);
	}
	return result;
}
