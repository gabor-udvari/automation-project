Automation Project using the DebOps framework
=========================

Playbooks for orchestrating Ubuntu servers, based on the [DebOps framework](https://github.com/debops).

## Installing

You need to install the DebOps framework first:
```bash
pip2 install debops
```

After that you can clone this repo and fill out the `ansible/inventory/hosts` file.
```bash
git clone git@github.com:gabor-udvari/automation-project.git
cd automation-project
mkdir ansible/inventory
touch hosts
```

Example hosts file:
```yml
[debops_all_hosts]
server1 ansible_connection=local
server2

[debops_service_nginx]
server2
```

## Using

You can use the `debops` command to launch the ansible playbooks. You can run specific playbooks or limit the run with tags:
```bash
debops playbooks/upgrade.yml
debops --tags 'role::nginx'
debops --limit server2
```
