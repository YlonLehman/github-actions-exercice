# github-actions-exercice

## Table of Contents

- [github-actions-exercice](#github-actions-exercice)
  - [Table of Contents](#table-of-contents)
  - [Resume](#resume)
  - [Makefile commands](#makefile-commands)
  - [Prerequisites](#prerequisites)
  - [Soluce](#soluce)
  - [Exercises](#exercises)
    - [1. First Job](#1-first-job)
    - [2. Test your project](#2-test-your-project)
    - [3. Code quality](#3-code-quality)
    - [4. Coverage](#4-coverage)
    - [5. Codecov](#5-codecov)
    - [6. Badges](#6-badges)
  - [Contact](#contact)

## Resume

This project allows you to learn Github Actions through several exercises. The solutions to these exercises can be found on the **“soluce”** branch.

## Makefile commands

To use this project, a Makefile is provided to simplify the commands for each task:

- **make**: generates the project executable in build/
- **make test**: generates the project test executable in build/
- **make coverage**: generates code coverage. The index.html file is located in build/coverage/html
- **make format**: formats the code directly according to the imposed formatting rules
- **make format-check**: checks that the code is correctly formatted
- **make lint**: checks that the code correctly complies with the linter rules
- **make clean**: completely deletes the build directory

## Prerequisites

Fork the project and work on the main branch to obtain all the features for the exercises.

## Soluce

The soluce of the exercices is on the soluce branch.

## Exercises

### 1. First Job

Implement your first **build.yaml** file containing a job that will compile the project.

### 2. Test your project

In a second file, **tests.yaml**, implement a job that tests the project. This job should only be performed if the job in build.yaml has been completed successfully.

### 3. Code quality

In the same tests.yaml file, implement two jobs for the linter and code format. These jobs run at the same time as the tests.

### 4. Coverage

Still in the same file, add a fourth job to perform project coverage. Create an artefact of the coverage.info file and upload it to GitHub.

### 5. Codecov

Go to [README Codecov](https://github.com/codecov/codecov-action#readme)and configure your project. You will need to create a secret on GitHub with the correct token.
Now create a final job to upload the coverage artefact to Codecov.

### 6. Badges

Add a badge to your README to see if CI is working correctly. Add a second badge to see the project coverage with Codecov.

## Contact

[Némo Cazin](https://github.com/nemocazin)
