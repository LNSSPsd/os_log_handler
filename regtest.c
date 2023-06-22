#include <stdio.h>
#include <regex.h>

int main() {
	regex_t regex_item;
	regmatch_t pmatch[12];
	regcomp(&regex_item, "%(\\{(((public|private|time_t|timeval|timespec|errno|iec-bytes|bitrate|iec-bitrate|uuid_t)(( *, *))?)*)\\})?((\\.)?\\*?([0-9]+)?)?(l{0,2})([a-zA-Z])", REG_EXTENDED);
	const char *tomatch="Hello, %{public}s!";
	int res=regexec(&regex_item, tomatch, 12, pmatch, 0);
	printf("res: %d\n",res);
	return 0;
}