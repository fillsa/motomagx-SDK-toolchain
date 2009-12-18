#include <ZApplication.h>
#include <ZNumPickerDlg.h>
#include <ZLabel.h>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static void usage(char * prog)
{
    fprintf(stderr, "Usage: %s [ -H HEADER_TEXT ] [ -V #VALUE ] [ -m #MINIMUM ]"
	            " [ -M #MAXIMUM  ] MESSAGE_TEXT\n",
	    prog);
    exit(-1);
}

int main(int argc, char **argv)
{
	ZApplication* a = new ZApplication(argc, argv);
	char * text = NULL;
	QString head("Header");
	QString msg;

	int val = 0;
	int minval = 0;
	int maxval = 999;
	int timeout = 0;

	int ch;
	while ((ch = getopt(argc, argv, "m:M:H:L:V:t:")) != EOF) {
	    switch (ch) {
	    case 'm':
		minval = atoi(optarg);
		break;
	    case 'M':
		maxval = atoi(optarg);
		break;
	    case 'V':
		val = atoi(optarg);
		break;
	    case 'L':
	        text = optarg;
		break;
	    case 'H':
	        head = QString::fromUtf8(optarg);
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

	msg = QString("");

	while (argc > 0) {
	    msg += QString::fromUtf8(argv[0]);
	    argc--; argv++;
	    if (argc)
		msg += QString("\n");
	}

	if (maxval < 9)
	    maxval = 9;

	if (minval > maxval)
	    minval = maxval;

	char tmp[256];
	sprintf(tmp , "%d", maxval);

	ZNumPickerDlg* dlg = new ZNumPickerDlg(strlen(tmp), NULL,
					       "ZNumPickerDlg", 0);
	ZNumModule* module = dlg->getNumModule();

	module->setMaxValue(maxval);
	module->setMinValue(minval);
	module->setValue(val);

	if (text) {
	    ZLabel * label = new ZLabel(QString::fromUtf8(text), module, NULL,
					0, (ZSkinService::WidgetClsID)4);

	    module->setLabel(label, (ZNumModule::RelativeAlignment)0);
	}

	dlg->setTitle(head);
	dlg->setInstructText(msg);

	if (timeout)
	    dlg->setAutoDismissTime(timeout*1000);

   	a->setMainWidget(dlg);
    	dlg->show();
   	a->exec();

	int result = dlg->result();

	if (result == 100) {
	    printf("Timeout\n");
	    result = 0;
	} else if (result != 1) {
	    printf("Canceled\n");
	    result = 0;
	} else {
	    result = dlg->getNumValue();
	    printf("%d", result);
	}

	return result;
}
