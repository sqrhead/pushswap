all :
	cc *.c -opushswap

runs:
	sh runner.sh
runm:
	sh runner_mid.sh
runl:
	sh runner_large.sh