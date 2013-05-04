# Builds all the projects in the solution...
.PHONY: all_projects
all_projects: li325 

# Builds project 'li325'...
.PHONY: li325
li325: 
	make --directory="li325/" --file=li325.makefile

# Cleans all projects...
.PHONY: clean
clean:
	make --directory="li325/" --file=li325.makefile clean

