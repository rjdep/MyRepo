# Kubernetes Deployment for OCS Production in a New Namespace

This repository contains the Kubernetes configuration files for deploying the Oracle Container Signing (OCS) production environment in a newly created namespace. These configurations include resources such as `ConfigMaps`, `ServiceAccounts`, `Roles`, `RoleBindings`, `ClusterRoles`, `ClusterRoleBindings`, `LimitRanges`, and `IngressClasses`. The deployment is tailored to manage the NGINX Ingress Controller, Notary Signer, Notary Server, Sigsign Server and other essential components within the `ocs-prod` namespace.


## Pre-Requisites
- **Kubernetes Cluster**: A functioning Kubernetes cluster where the resources will be deployed [Kubernetes Cluster](https://docs.oracle.com/en-us/iaas/Content/ContEng/Concepts/contengoverview.htm)
- **Cluster Access**: Sufficient access rights to the cluster to create and manage namespaces and other resources. [Access Cluster](https://docs.oracle.com/en-us/iaas/Content/ContEng/Tasks/contengaccessingclusterkubectl.htm)
- **OCIR Repository Access**: Access to the Oracle Cloud Infrastructure Registry (OCIR) to pull necessary images for the deployment. [Container Registry](https://docs.oracle.com/en-us/iaas/Content/Registry/home.htm)



## Gather Required Information
**Required Fields:**
- `compartment_ocid`: Compartment ID where to create all resources.
- `tenancy_ocid`: Tenancy OCID.
- `vcn_id`: OCID of the VCN in use.
- `nodepool_subnet_id`: Subnet ID for node pool.
- `lb_subnet_id`: Subnet ID for Service Load Balancer.
- `api_endpoint_subnet_id`: Subnet ID for API endpoints.
- `pods_subnet_id`: Subnet ID for pods.
- `node_pool_image_id`: OCID of the image used.
- `use_existing_vcn`: Indicates whether to use an existing VCN.
- `use_existing_nsg`: Indicates whether to use an existing NSG.
- `vcn_native`: Indicates whether to use a native VCN.
- `is_api_endpoint_subnet_public`: Indicates whether the API endpoint subnet is public.
- `is_lb_subnet_public`: Indicates whether the LB subnet is public.
- `is_nodepool_subnet_public`: Indicates whether the node pool subnet is public.
- `oci_vcn_ip_native`: Indicates whether to use OCI native IP.
- `cluster_options_add_ons_is_kubernetes_dashboard_enabled`: Indicates whether Kubernetes dashboard is enabled.
- `cluster_options_add_ons_is_tiller_enabled`: Indicates whether Tiller is enabled.
- `cluster_options_admission_controller_options_is_pod_security_policy_enabled`: Indicates whether PodSecurityPolicy admission controller is enabled.
- `eviction_grace_duration`: Eviction grace duration.
- `is_force_delete_after_grace_duration`: Indicates whether to force delete after grace duration.
- `node_eviction_node_pool_settings`: Indicates whether node pool eviction settings are enabled.
- `api_endpoint_nsg_ids`: NSG IDs for API endpoints.
- `pods_nsg_ids`: NSG IDs for pods.
- `oke_cluster_name`: Name of the OKE cluster.
- `cluster_type`: The cluster type.
- `k8s_version`: Kubernetes version.
- `pool_name`: Name of the node pool.
- `node_shape`: Node shape.
- `max_pods_per_node`: Maximum number of pods per node.
- `node_linux_version`: Linux version for nodes.
- `node_count`: Number of nodes.
- `node_pool_image_type`: Type of image used for node pool.
- `node_pool_boot_volume_size_in_gbs`: Boot volume size for node pool.
- `node_ocpus`: Number of CPUs per node.
- `node_memory`: Memory in GB per node.
- `node_pool_initial_node_labels_key`: Initial node labels key.
- `node_pool_initial_node_labels_value`: Initial node labels value.
- `cluster_kube_config_token_version`: Kubernetes config token version.
- `ssh_public_key`: Full file path of the SSH public key for API access.
- `defined_tags`: Defined tags.


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
- [Oracle Oci Oke Docs](https://oracle-terraform-modules.github.io/terraform-oci-oke/)
- [Accessing a Cluster Using Kubectl](https://docs.oracle.com/en-us/iaas/Content/ContEng/Tasks/contengaccessingclusterkubectl.htm)
- [Terraform: Create a Kubernetes Cluster](https://docs.oracle.com/en-us/iaas/developer-tutorials/tutorials/tf-cluster/01-summary.htm)
