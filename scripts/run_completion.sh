_run_completion()
{
   local cur="${COMP_WORDS[COMP_CWORD]}"
   local presets="Debug Release Distro"

   COMPREPLY=($(compgen -W "$presets" -- "$cur"))
}

complete -F _run_completion run.sh