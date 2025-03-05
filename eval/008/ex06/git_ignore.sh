#!/bin/sh

git ls-files --others --ignored --exclude-standard $(git rev-parse --show-toplevel)
