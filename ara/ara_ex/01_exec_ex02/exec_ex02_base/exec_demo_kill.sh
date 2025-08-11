#!/bin/sh

echo exec_demo : start kill mga_emd
pgrep mga_emd | xargs kill -s 15

echo exec_demo kill ara-state-change
pgrep ara-state-change | xargs kill
pgrep ara-state-chang | xargs kill
