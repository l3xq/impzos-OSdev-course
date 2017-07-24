
Vagrant.configure("2") do |config|

  # Which box to configure
  config.vm.box = "npalm/mint17-amd64-cinnamon"

  # Script that should be executed when creating new Vagrant box

  $script = %Q{
    sudo apt-get update
    sudo apt-get install nasm make build-essential grub qemu zip xorriso g++ binutils libc6-dev-i386 -y
    sudo apt-get install grub -y
  }

  config.vm.provision :shell, :inline => $script

end
