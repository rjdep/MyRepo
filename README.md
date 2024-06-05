# Oracle Instance Creation and Block Volume attachment Through Terraform

This project provides Terraform to automate the creation of compute instance in your Oracle Cloud Infrastructure tenancy. It also adds a block volume to the created instance.


## Pre-Requisites
- **Install Terraform**: Follow this [Install Terraform](https://docs.oracle.com/en-us/iaas/developer-tutorials/tutorials/tf-provider/01-summary.htm#) to install the latest version of Terraform that's supported for OCI Resource Manager.
- **OCI API Key (Private Key)**: Follow this [Oracle API Key Generation link](https://docs.oracle.com/en-us/iaas/Content/API/Concepts/apisigningkey.htm#two) to create the necessary API key and config details.
 - Note: Typically the API Key can be generated from your profile [page](https://cloud.oracle.com/identity/domains/my-profile/api-keys) > API Keys (left) > Add API Key


## Gather Required Information
**Required Fields:**
- `region`: Specifies the OCI region where resources will be created.
- `compartment_ocid`: Specifies the compartment ID where all resources will be created.
- `user_ocid`: Specifies the `OCID` where resources will be created.
- `subnet_ocid`: The `OCID` of an existing subnet that will be used when creating an instance.
- `tenancy_ocid`: Specifies the Tenancy `OCID` for the OCI account.
- `shape`: Specifies the shape of the instance. The default shape is set to "VM.Standard.A1.Flex".
- `source_ocid`: Specifies the Source `OCID` of the instance
- `ocpus`: Specifies the number of Oracle Compute Units (OCPU) for the instance. Default value is 1.
- `vcpus`: Specifies the number of Virtual CPUs (VCPUs) for the instance. Default value is 2.
- `memory_in_gbs`: Specifies the memory configuration for the instance in gigabytes (GBs). Default value is 6.
- `instance_ocid`: Specifies the Instance `OCID`.
- `ssh_public_key`: Specifies the full file path of the SSH public key to be used for API access.
- `ssh_private_key`: Specifies the full file path of the SSH private key to be used for API access.
- `private_key_path`: Specifies the full file path of the private key to be used for API access.
- `public_key_path`: Specifies the full file path of the public key to be used for API access.
- `fingerprint`: Specifies the PEM fingerprint for the private key.

## Setup and Run
Edit the `var.tf` file with the required Information.
Once the setup is done:
```bash
terraform init
```
```bash
terraform plan
```
```bash
terraform apply
```

## References
- [Oracle Launch Instance Docs](https://docs.oracle.com/en-us/iaas/developer-tutorials/tutorials/tf-compute/01-summary.htm)
- [Oracle Block Volume Docs](https://docs.oracle.com/en-us/iaas/Content/Block/Tasks/creatingavolume.htm)
- [HashiCorp oci_core_volume](https://registry.terraform.io/providers/oracle/oci/latest/docs/resources/core_volume.html)
