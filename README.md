# c-frontend

## What is this?
a frontend framework for c

## Why?
why not

## How to use?

### Clone it
`git clone https://github.com/doctor112-1/c-frontend.git`

### Editing

```
├── README.md
├── build.sh
├── main.c
├── page.html
├── preprocess.sh
└── site
    ├── mainElement.c
    └── vars.h
```
the main.c is the main file that calls the `mainElement()` function from mainElement.c and with the output of it renders the page. if you want to edit the page, edit what the `mainElement()` returns in the mainElement.c file.


### JSX

To use variables inside your return statements first declare them globally. Make sure to name them in the format `name_vartype`. There are only two vartypes, `int`, and `string`. Then, in the vars.h file define them (ie: `extern int my_var;`).

### Building it
to build it run the `build.sh` file.

### Viewing it
no web server yet so just run `python -m http.server 8000`
