make m = launch mandatory tests
make b = launch bonus tests
make a = launch mandatory tests + bonus tests
make [funtion name] = launch associated test ex: make calloc

make dockerm = launch mandatory tests in linux container
make dockerb = launch bonus tests in linux container
make dockera = launch mandatory tests + bonus tests in linux container
make docker[funtion name] = launch associated test in linux container ex: make dockercalloc
Thanks to gurival- for the docker idea (https://github.com/grouville/valgrind_42)

make vs[funtion name] = open the corresponding tests in vscode ex: make vscalloc