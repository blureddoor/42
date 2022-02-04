#!/bin/bash
git status -s --ignored | grep !! | tr '!!' ' ' 
